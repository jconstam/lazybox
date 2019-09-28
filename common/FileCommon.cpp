#include "FileCommon.hpp"

#include <fstream>
#include <iostream>
#include <experimental/filesystem>

#include <sys/stat.h>

using namespace std;

string FileCommon::readEntireFile( string filePath )
{
    ifstream fileStream( filePath );
    string fileContents;

    fileStream.seekg( 0, ios::end );   
    fileContents.reserve( fileStream.tellg( ) );
    fileStream.seekg( 0, ios::beg );

    fileContents.assign( istreambuf_iterator<char>( fileStream ), istreambuf_iterator<char>( ) );

    return fileContents;
}

bool FileCommon::fileExists( string filePath )
{
    struct stat buffer;   
    return ( stat( filePath.c_str(), &( buffer ) ) == 0 ); 
}

string FileCommon::trimString( string raw )
{
    while( ( raw.length( ) > 0 ) && ( isspace( raw[ 0 ] ) ) )
    {
        raw = raw.substr( 1 );
    }

    return raw;
}

 string FileCommon::removeWhitespace( string raw )
 {
    for( size_t i = 0U; i < raw.length( ); i++ )
    {
        if( isspace( raw[ i ] ) )
        {
            raw.replace( i, 1, "" );
        }
    }

    return raw;
 }