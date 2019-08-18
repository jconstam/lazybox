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
        ifstream fileStream( file );
        string fileContents;
        
        fileStream.seekg( 0, ios::end );   
        fileContents.reserve( fileStream.tellg( ) );
        fileStream.seekg( 0, ios::beg );
        
        fileContents.assign( istreambuf_iterator<char>( fileStream ), istreambuf_iterator<char>( ) );

        if( fileContents.find( LAZYBOX_MARKER ) != string::npos )
        {
            cout << "Command File \"" << file << "\" is a valid command!" << endl;

            LazyBoxCommand command( fileContents );

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
    addFileTimestamp( fileStream );

    fileStream << "#ifndef COMMANDS_HPP__" << endl << "#define COMMANDS_HPP__" << endl << endl;
    
    for( map<string, LazyBoxCommand>::iterator it = m_commands.begin(); it != m_commands.end(); it++ )
    {
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
    addFileTimestamp( fileStream );

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
    addFileTimestamp( fileStream, false );

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
    addFileTimestamp( fileStream, false );

    fileStream.close( );
}

void CmdFileScanner::addFileTimestamp( ofstream& fileStream, bool cStyle )
{
    time_t time = chrono::system_clock::to_time_t( chrono::system_clock::now() );

    if( cStyle )
    {
        fileStream << "//";
    }
    else
    {
        fileStream << "#";
    }

    fileStream << " This file was automatically generated on " << ctime( &time ) << endl;
}
