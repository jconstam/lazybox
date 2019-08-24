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
    ofstream fileStream;

    cout << "Writing to Command Include File \"" << includeFilePath << "\"" << endl;

    fileStream.open( includeFilePath );
    addFileHeader( fileStream );

    fileStream << "#ifndef COMMANDS_HPP__" << endl << "#define COMMANDS_HPP__" << endl << endl;
    
    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        if( ! it->second.getIsCPP( ) )
        {
            fileStream << "extern \"C\" ";
        }
        fileStream << "int " << it->second.getFunction( ) << "( int argc, char* argv[ ] );" << endl;
    }

    fileStream << endl << "#endif" << endl;

    fileStream.close( );
}

void CmdFileScanner::writeCmdListfile( string listFilePath )
{
    ofstream fileStream;

    cout << "Writing to Command List File \"" << listFilePath << "\"" << endl;

    fileStream.open( listFilePath );
    addFileHeader( fileStream );

    fileStream << "#include \"cmdList.hpp\"" << endl << endl;
    fileStream << "const std::map<std::string, CmdFunc> commandList =" << endl;
    fileStream << "{" << endl;
    
    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        fileStream << "\t{ \"" << it->second.getName( ) << "\", " << it->second.getFunction( ) << " }," << endl;
    }

    fileStream << "};" << endl;

    fileStream.close( );
}

void CmdFileScanner::writeSymlinkScriptfile( string scriptFilePath )
{
    ofstream fileStream;

    cout << "Writing to Symlink Script File \"" << scriptFilePath << "\"" << endl;

    fileStream.open( scriptFilePath );
    addFileHeader( fileStream, false );

    fileStream << "#!/bin/bash" << endl << endl;
    fileStream << "if [ \"$#\" -ne \"1\" ]; then" << endl;
    fileStream << "\techo \"Usage: $0 <Main Binary>\"" << endl;
    fileStream << "\texit -1" << endl;
    fileStream << "fi" << endl << endl;
    fileStream << "MAIN_PROJECT_NAME=$1" << endl << endl;

    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
        fileStream << "ln -f -s ${MAIN_PROJECT_NAME} " << it->second.getName( ) << endl;
    }

    fileStream.close( );

    chmod( scriptFilePath.c_str( ), S_IRWXU );
}
void CmdFileScanner::writeCMakeTestfile( string testFilePath )
{
    ofstream fileStream;

    cout << "Writing to CMake Test file \"" << testFilePath << "\"" << endl;

    fileStream.open( testFilePath );
    addFileHeader( fileStream, false );

    fileStream << "add_test( lazybox ${OUTPUT_PATH}/lazybox )" << endl;
    fileStream << "set_tests_properties( lazybox PROPERTIES PASS_REGULAR_EXPRESSION \"LazyBox - BusyBox\'s less portable, less functional cousin.\" )" << endl;
    fileStream << endl;

    for( map<string, LazyBoxCommand>::iterator cmdIter = m_commands.begin( ); cmdIter != m_commands.end( ); cmdIter++ )
    {
        vector<LazyBoxCommandTest> tests = cmdIter->second.getTests( );
        for( vector<LazyBoxCommandTest>::iterator testIter = tests.begin( ); testIter != tests.end( ); testIter++ )
        {
            writeTestToCmakeTestFile( fileStream, cmdIter->second, *testIter );
        }
    }

    fileStream.close( );
}

void CmdFileScanner::writeTestToCmakeTestFile( ofstream& fileStream, LazyBoxCommand command, LazyBoxCommandTest test )
{
    string testName = command.getName( ) + "_" + test.getName( );
    string testNameSL = command.getName( ) + "_" + test.getName( ) + "_symlink";

    fileStream << "add_test( " << testName << " python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/lazybox " << command.getName( ) << " ";
    fileStream << test.getParameters( ) << " CMD_OUTPUT_SPLITTER " << test.getOutput( ) << " )" << endl;
    fileStream << "add_test( " << testNameSL << " python3 ${SCRIPT_PATH}/runTest.py ${OUTPUT_PATH}/" << command.getName( ) << " ";
    fileStream << test.getParameters( ) << " CMD_OUTPUT_SPLITTER " << test.getOutput( ) << " )" << endl;
    fileStream << endl;
}

void CmdFileScanner::addFileHeader( ofstream& fileStream, bool cStyle )
{
    if( cStyle )
    {
        fileStream << "//";
    }
    else
    {
        fileStream << "#";
    }

    fileStream << " This file was automatically generated.  Do not modify." << endl << endl;
}
