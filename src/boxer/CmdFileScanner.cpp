#include "CmdFileScanner.hpp"

#include <ctime>
#include <chrono>
#include <cwctype>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <experimental/filesystem>

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";
static const string NAME_MARKER = "@name";
static const string DESCRIP_MARKER = "@descrip";
static const string FUNCTION_MARKER = "@function";

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

    time_t time = chrono::system_clock::to_time_t( chrono::system_clock::now() );

    fileStream << "// This file was automatically generated on " << ctime( &time ) << endl;
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

    time_t time = chrono::system_clock::to_time_t( chrono::system_clock::now() );

    fileStream << "// This file was automatically generated on " << ctime( &time ) << endl;
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

LazyBoxCommand::LazyBoxCommand( string fileContents )
{
    m_name = "";
    m_descrip = "";
    m_function = "";

    parseField( fileContents, NAME_MARKER, m_name );
    parseField( fileContents, DESCRIP_MARKER, m_descrip );
    parseField( fileContents, FUNCTION_MARKER, m_function );
}

bool LazyBoxCommand::isValid( )
{
    if( m_name == "" )
    {
        return false;
    }
    else if( m_descrip == "" )
    {
        return false;
    }
    else if( m_function == "" )
    {
        return false;
    }
    else
    {
        return true;
    }
}

string LazyBoxCommand::getName( )
{
    return m_name;
}
string LazyBoxCommand::getDescrip( )
{
    return m_descrip;
}
string LazyBoxCommand::getFunction( )
{
    return m_function;
}

void LazyBoxCommand::parseField( string fileContents, string marker, string& fieldData )
{
    size_t markerLocation = fileContents.find( marker );
    if( markerLocation != string::npos )
    {
        size_t endOfLine = fileContents.find( "\n", markerLocation );
        size_t dataStart = markerLocation + marker.length( );

        fieldData = fileContents.substr( dataStart, endOfLine - dataStart );
        while( iswspace( fieldData[ 0 ] ) )
        {
            fieldData = fieldData.substr( 1 );
        }
        while( iswspace( fieldData[ fieldData.length( ) - 1 ] ) )
        {
            fieldData = fieldData.substr( 0, fieldData.length( ) - 1 );
        }
    }
}