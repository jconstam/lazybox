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