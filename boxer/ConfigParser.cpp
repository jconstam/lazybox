#include "ConfigParser.hpp"

#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>

#include "FileCommon.hpp"

using namespace std;

ConfigParser::ConfigParser( )
{

}

bool ConfigParser::ParseFile( string filePath )
{
    if( !FileCommon::fileExists( filePath ) )
    {
        return false;
    }
    
    readConfigFile( FileCommon::readEntireFile( filePath ) );

    return true;
}

void ConfigParser::readConfigFile( std::string fileContents )
{
    size_t startIndex = 0U;
    size_t endOfLineIndex = 0U;

    while( endOfLineIndex != string::npos )
    {
        endOfLineIndex = fileContents.find( "\n", startIndex );

        string currLine = fileContents.substr( startIndex, endOfLineIndex - startIndex );
        while( isspace( currLine[ 0 ] ) )
        {
            currLine = currLine.substr( 1 );
        }

        cout << currLine << endl;

        startIndex = endOfLineIndex + 1U;
    }
}