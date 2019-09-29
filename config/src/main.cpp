#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#include <getopt.h>

#include "ConfigParser.hpp"

using namespace std;

typedef struct
{
	string configPath;
} CONFIG_PARAMS;

static bool parseParams( int argc, char* argv[], CONFIG_PARAMS* params )
{
    int opt = 0;
	while( opt != -1 )  
    {  
		opt = getopt( argc, argv, "c:" );
        switch( opt )  
        {  
            case 'c': 
				params->configPath = optarg;
				cout << "Using Config Path \"" << params->configPath << "\"" << endl;
				break;
			case -1:
				break;
            case '?':  
			default:
				cout << "Unknown Option: " << optopt << endl;
				return false;
        }  
    }

	if( params->configPath == "" )
	{
		cout << "Config Path not specified (use -c)" << endl;
		return false;
	}

	return true;
}

static bool checkOnFlag( string flag )
{
	string input;
	while( ( input != "y" ) && ( input != "n" ) )
	{
		cout << "Include flag \"" << flag << "\"? (y/n): ";
		cin >> input;

		transform( input.begin( ), input.end( ), input.begin( ), []( unsigned char c ){ return tolower( c ); } );
	}

	return ( input == "y" );
}

int main( int argc, char* argv[] )
{
	system( "clear" );

	CONFIG_PARAMS params = { "" };
	if( ! parseParams( argc, argv, &( params ) ) )
	{
		cout << "Could not parse command line arguments" << endl;
		return 1;
	}
	
	ConfigParser parser;
	string configFilePath = params.configPath + "/default.config";
	if( !parser.ParseFile( configFilePath ) )
	{
		cout << "Could not parse configuration file \"" << configFilePath << "\"." << endl;
		return 1;
	}

	unordered_set<string> configFlags;
	unordered_set<string> configFlagsFromFile = parser.GetConfigFlags( );
	for( const auto& flag: configFlagsFromFile )
	{
		if( checkOnFlag( flag ) )
		{
			configFlags.insert( flag );
		}
	}

	ConfigParser::GenerateFile( params.configPath + "/.config", configFlags );

	system( "clear" );

	return 0;
}