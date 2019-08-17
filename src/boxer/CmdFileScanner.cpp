#include "CmdFileScanner.hpp"

#include <fstream>
#include <iostream>
#include <streambuf>
#include <experimental/filesystem>

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";

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
        
        fileStream.seekg( 0, std::ios::end );   
        fileContents.reserve( fileStream.tellg( ) );
        fileStream.seekg( 0, std::ios::beg );
        
        fileContents.assign( istreambuf_iterator<char>( fileStream ), std::istreambuf_iterator<char>( ) );

        if( fileContents.find( LAZYBOX_MARKER ) != string::npos )
        {
            found = true;
            cout << "Command File \"" << file << "\" is a valid command!" << endl;
        }
    }

    return found;
}

LazyBoxCommand::LazyBoxCommand( )
{
    m_name = "";
    m_descrip = "";
    m_function = "";
}