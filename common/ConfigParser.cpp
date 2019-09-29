#include "ConfigParser.hpp"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

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
        cout << "Could not find config file \"" << filePath << "\"." << endl;

        return false;
    }
    
    readConfigFile( FileCommon::readEntireFile( filePath ) );

    return true;
}

bool ConfigParser::IsInConfig( string configFlag )
{
    return ( m_configFlags.find( configFlag ) != m_configFlags.end( ) );
}

void ConfigParser::GenerateFile( string filePath, unordered_set<string> configFlags )
{
	ofstream configFile;
	configFile.open( filePath );

	configFile << "# Generated config file" << endl << endl;
	for( const auto& flag: configFlags )
	{
		configFile << "CONFIG_" << flag << "=y" << endl;
	}
	configFile << endl;

	configFile.close( );
}

unordered_set<string> ConfigParser::GetConfigFlags( )
{
    return m_configFlags;
}

void ConfigParser::readConfigFile( std::string fileContents )
{
    size_t startIndex = 0U;
    size_t endOfLineIndex = 0U;

    while( endOfLineIndex != string::npos )
    {
        endOfLineIndex = fileContents.find( "\n", startIndex );

        string currLine = FileCommon::removeWhitespace( fileContents.substr( startIndex, endOfLineIndex - startIndex ) );

        if( ( currLine != "" ) && ( currLine.compare( 0, 1, "#" ) != 0 ) )
        {
            size_t length = currLine.length( );
            if( currLine.compare( length - 2, 2, "=y" ) == 0 )
            {
                if( currLine.compare( 0, 7, "CONFIG_" ) == 0 )
                {
                    m_configFlags.insert( currLine.substr( 7, length - 7 - 2 ) );
                }
                else
                {
                    m_configFlags.insert( currLine.substr( 0, length -2  ) );
                }
            }
        }

        startIndex = endOfLineIndex + 1U;
    }
}