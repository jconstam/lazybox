#include "CmdFileScanner.hpp"

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

            found = command.isValid( );
            if( found )
            {
                m_cmdList.push_back( command );
            }
        }
    }

    return found;
}

void CmdFileScanner::writeCmdIncludeFile( std::string includeFilePath )
{
    ofstream fileStream;
    fileStream.open( includeFilePath );

    fileStream << "#ifndef COMMANDS_HPP__" << endl << "#define COMMANDS_HPP__" << endl << endl;

    for( LazyBoxCommand &command : m_cmdList )
    {
        fileStream << "int " << command.getFunction( ) << "( int argc, char* argv[ ] );" << endl;
    }

    fileStream << endl << "#endif" << endl;

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