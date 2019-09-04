#include "CmdFileScanner.hpp"

#include <ctime>
#include <chrono>
#include <cwctype>
#include <iostream>
#include <experimental/filesystem>

#include <sys/stat.h>

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";
static const string NAME_MARKER = "@name";
static const string DESCRIP_MARKER = "@descrip";
static const string FUNCTION_MARKER = "@function";
static const string TEST_MARKER = "@test";
static const string TESTPARAM_MARKER = "@testparam";
static const string TESTOUTPUT_MARKER = "@testoutput";

CmdFileScanner::CmdFileScanner( )
{
}

bool CmdFileScanner::scanForFiles( string path )
{
    for( const auto & entry : experimental::filesystem::directory_iterator( path ) )
    {
        m_fileList.push_back( entry.path( ).generic_string( ) );
        cout << "Found Command File \"" << entry.path( ).generic_string( ) << "\"" << endl;
    }

    return ( m_fileList.size( ) > 0 );
}

bool CmdFileScanner::parseFiles( )
{
    bool found = false;
    for( const string file : m_fileList )
    {
        string fileContents = readEntireFile( file );
        if( fileContents.find( LAZYBOX_MARKER ) != string::npos )
        {
            cout << "Command File \"" << file << "\" is a valid command!" << endl;

            LazyBoxCommand command( file, fileContents );

            if( command.isValid( ) )
            {
                map<string,LazyBoxCommand>::iterator it = m_commands.find( command.getName( ) );
                if( it == m_commands.end( ) )
                {
                    found = true;
                    m_commands[ command.getName( ) ] = command;
                }
            }
        }
    }

    return found;
}

void CmdFileScanner::writeCmdIncludeFile( string includeFilePath )
{
    stringstream output;

    cout << "Writing to Command Include File \"" << includeFilePath << "\"" << endl;

    addFileHeader( output );

    output << "#ifndef COMMANDS_HPP__" << endl << "#define COMMANDS_HPP__" << endl << endl;
    
    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        if( ! it->second.getIsCPP( ) )
        {
            output << "extern \"C\" ";
        }
        output << "int " << it->second.getFunction( ) << "( int argc, char* argv[ ] );" << endl;
    }

    output << endl << "#endif" << endl;

    writeFileIfChanged( includeFilePath, output.str( ) );
}

void CmdFileScanner::writeCmdListfile( string listFilePath )
{
    stringstream output;

    cout << "Writing to Command List File \"" << listFilePath << "\"" << endl;

    addFileHeader( output );

    output << "#include \"cmdList.hpp\"" << endl << endl;
    output << "const std::map<std::string, CmdFunc> CmdList::commandList =" << endl;
    output << "{" << endl;
    
    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        output << "\t{ \"" << it->second.getName( ) << "\", " << it->second.getFunction( ) << " }," << endl;
    }

    output << "};" << endl;

    writeFileIfChanged( listFilePath, output.str( ) );
}

void CmdFileScanner::writeSymlinkScriptfile( string scriptFilePath )
{
    stringstream output;

    cout << "Writing to Symlink Script File \"" << scriptFilePath << "\"" << endl;

    addFileHeader( output, false );

    output << "#!/bin/bash" << endl << endl;
    output << "if [ \"$#\" -ne \"1\" ]; then" << endl;
    output << "\techo \"Usage: $0 <Main Binary>\"" << endl;
    output << "\texit -1" << endl;
    output << "fi" << endl << endl;
    output << "MAIN_PROJECT_NAME=$1" << endl << endl;

    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        output << "ln -f -s ${MAIN_PROJECT_NAME} " << it->second.getName( ) << endl;
    }

    writeFileIfChanged( scriptFilePath, output.str( ) );

    chmod( scriptFilePath.c_str( ), S_IRWXU );
}
void CmdFileScanner::writeCMakeTestfile( string testFilePath )
{
    stringstream output;

    cout << "Writing to CMake Test file \"" << testFilePath << "\"" << endl;

    addFileHeader( output, false );

    output << "add_test( lazybox ${OUTPUT_PATH}/lazybox )" << endl;
    output << "set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION \"LazyBox - BusyBox\'s less portable, less functional cousin.\" )" << endl;
    output << endl;

    for( map<string, LazyBoxCommand>::iterator cmdIter = m_commands.begin( ); cmdIter != m_commands.end( ); cmdIter++ )
    {
        vector<LazyBoxCommandTest> tests = cmdIter->second.getTests( );
        for( vector<LazyBoxCommandTest>::iterator testIter = tests.begin( ); testIter != tests.end( ); testIter++ )
        {
            writeTestToCmakeTestFile( output, cmdIter->second, *testIter, testFilePath );
        }
    }

    writeFileIfChanged( testFilePath, output.str( ) );
}

void CmdFileScanner::writeCMakeCommandsFile( string commandsFilePath )
{
    stringstream output;

    cout << "Writing to CMake Commands file \"" << commandsFilePath << "\"" << endl;

    addFileHeader( output, false );

    output << "set( COMMAND_SOURCES_C" << endl;
    for( map<string, LazyBoxCommand>::iterator cmdIter = m_commands.begin( ); cmdIter != m_commands.end( ); cmdIter++ )
    {
        if( ! cmdIter->second.getIsCPP( ) )
        {
            output << "\t${COMMAND_SOURCE_DIR}/" << cmdIter->second.getFileNameShort( ) << endl;
        }
    }

    output << "\tPARENT_SCOPE" << endl;
    output << ")" << endl;

    output << "set( COMMAND_SOURCES_CPP" << endl;
    for( map<string, LazyBoxCommand>::iterator cmdIter = m_commands.begin( ); cmdIter != m_commands.end( ); cmdIter++ )
    {
        if( cmdIter->second.getIsCPP( ) )
        {
            output << "\t${COMMAND_SOURCE_DIR}/" << cmdIter->second.getFileNameShort( ) << endl;
        }
    }

    output << "\tPARENT_SCOPE" << endl;
    output << ")" << endl;

    writeFileIfChanged( commandsFilePath, output.str( ) );
}

void CmdFileScanner::writeTestToCmakeTestFile( stringstream& output, LazyBoxCommand command, LazyBoxCommandTest test, string testFilePath )
{
    string execPath = testFilePath;
    size_t lastIndex = execPath.find_last_of( '/' );
    if( lastIndex < execPath.length( ) )
    {
        execPath = execPath.substr( 0, lastIndex );
    }

    string testName = command.getName( ) + "_" + test.getName( );
    string testNameSL = command.getName( ) + "_" + test.getName( ) + "_symlink";
    string testNameVG = command.getName( ) + "_" + test.getName( ) + "_valgrind";

    output << "add_test( NAME " << testName << " WORKING_DIRECTORY " << execPath << " COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox " << command.getName( ) << " ";
    output << test.getParameters( ) << " CMD_OUTPUT_SPLITTER " << test.getOutput( ) << " )" << endl;
    output << "add_test( NAME " << testNameSL << " WORKING_DIRECTORY " << execPath << " COMMAND ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/" << command.getName( ) << " ";
    output << test.getParameters( ) << " CMD_OUTPUT_SPLITTER " << test.getOutput( ) << " )" << endl;
    output << "add_test( NAME " << testNameVG << " WORKING_DIRECTORY " << execPath << " COMMAND ${SCRIPT_PATH}/runValgrind.sh ";
    output << "${OUTPUT_PATH}/" << command.getName( ) << " " << test.getParameters( ) << " )" << endl;
    output << endl;
}

void CmdFileScanner::addFileHeader( stringstream& output, bool cStyle )
{
    if( cStyle )
    {
        output << "//";
    }
    else
    {
        output << "#";
    }

    output << " This file was automatically generated.  Do not modify." << endl << endl;
}

string CmdFileScanner::readEntireFile( string filePath )
{
    ifstream fileStream( filePath );
    string fileContents;

    fileStream.seekg( 0, ios::end );   
    fileContents.reserve( fileStream.tellg( ) );
    fileStream.seekg( 0, ios::beg );

    fileContents.assign( istreambuf_iterator<char>( fileStream ), istreambuf_iterator<char>( ) );

    return fileContents;
}

void CmdFileScanner::writeFileIfChanged( string filePath, string contents )
{
    bool newContent = true;
    struct stat buffer;   
    if( stat( filePath.c_str( ), &( buffer ) ) == 0 )
    {
        string oldContent = readEntireFile( filePath );
        if( contents == oldContent )
        {
            cout << "\tCurrent and new content of \"" << filePath << "\" are the same." << endl;
            newContent = false;
        }
    }

    if( newContent )
    {
        ofstream fileStream;
        fileStream.open( filePath );
        fileStream << contents;
        fileStream.close( );   
    }
}