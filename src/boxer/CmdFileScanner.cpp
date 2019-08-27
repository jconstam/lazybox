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
        bool isCPP = file.substr( file.length( ) - 3 ) == "cpp";

        ifstream fileStream( file );
        string fileContents;
        
        fileStream.seekg( 0, ios::end );   
        fileContents.reserve( fileStream.tellg( ) );
        fileStream.seekg( 0, ios::beg );
        
        fileContents.assign( istreambuf_iterator<char>( fileStream ), istreambuf_iterator<char>( ) );

        if( fileContents.find( LAZYBOX_MARKER ) != string::npos )
        {
            cout << "Command File \"" << file << "\" is a valid command!" << endl;

            LazyBoxCommand command( isCPP, fileContents );

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

    ofstream fileStream;
    fileStream.open( includeFilePath );
    fileStream << output.str( );
    fileStream.close( );
}

void CmdFileScanner::writeCmdListfile( string listFilePath )
{
    stringstream output;

    cout << "Writing to Command List File \"" << listFilePath << "\"" << endl;

    addFileHeader( output );

    output << "#include \"cmdList.hpp\"" << endl << endl;
    output << "const std::map<std::string, CmdFunc> commandList =" << endl;
    output << "{" << endl;
    
    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        output << "\t{ \"" << it->second.getName( ) << "\", " << it->second.getFunction( ) << " }," << endl;
    }

    output << "};" << endl;

    ofstream fileStream;
    fileStream.open( listFilePath );
    fileStream << output.str( );
    fileStream.close( );
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

    ofstream fileStream;
    fileStream.open( scriptFilePath );
    fileStream << output.str( );
    fileStream.close( );

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
            writeTestToCmakeTestFile( output, cmdIter->second, *testIter );
        }
    }

    ofstream fileStream;
    fileStream.open( testFilePath );
    fileStream << output.str( );
    fileStream.close( );
}

void CmdFileScanner::writeTestToCmakeTestFile( stringstream& output, LazyBoxCommand command, LazyBoxCommandTest test )
{
    string testName = command.getName( ) + "_" + test.getName( );
    string testNameSL = command.getName( ) + "_" + test.getName( ) + "_symlink";

    output << "add_test( " << testName << " ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox " << command.getName( ) << " ";
    output << test.getParameters( ) << " CMD_OUTPUT_SPLITTER " << test.getOutput( ) << " )" << endl;
    output << "add_test( " << testNameSL << " ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/" << command.getName( ) << " ";
    output << test.getParameters( ) << " CMD_OUTPUT_SPLITTER " << test.getOutput( ) << " )" << endl;
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
