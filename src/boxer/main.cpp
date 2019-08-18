#include <iostream>
#include <experimental/filesystem>

#include <getopt.h>

#include "CmdFileScanner.hpp"

using namespace std;

typedef struct
{
	string cmdFilePath;
	string cmdIncludeFile;
	string cmdListFile;
} BOXER_PARAMS;

static bool parseParams( int argc, char* argv[], BOXER_PARAMS* params )
{
    int opt = 0;
	while( opt != -1 )  
    {  
		opt = getopt( argc, argv, "c:i:l:" );
        switch( opt )  
        {  
            case 'c': 
				params->cmdFilePath = optarg;
				cout << "Using Command File Path \"" << params->cmdFilePath << "\"" << endl;
				break;
			case 'i':
				params->cmdIncludeFile = experimental::filesystem::absolute( optarg );
				cout << "Using Command Include File \"" << params->cmdIncludeFile << "\"" << endl;
				break;
			case 'l':
				params->cmdListFile = experimental::filesystem::absolute( optarg );
				cout << "Using Command List File \"" << params->cmdListFile << "\"" << endl;
				break;
			case -1:
				break;
            case '?':  
			default:
				cout << "Unknown Option: " << optopt << endl;
				return false;
        }  
    }

	if( params->cmdFilePath == "" )
	{
		cout << "Command File Path not specified (use -c)" << endl;
		return false;
	}
	if( params->cmdIncludeFile == "" )
	{
		cout << "Command Include File not specified (use -i)" << endl;
		return false;
	}
	if( params->cmdListFile == "" )
	{
		cout << "Command List File not specified (use -l)" << endl;
		return false;
	}

	return true;
}

int main( int argc, char* argv[] )
{
	BOXER_PARAMS params = { "", "" };
	if( ! parseParams( argc, argv, &( params ) ) )
	{
		cout << "Could not parse command line arguments" << endl;
		return -1;
	}
	
	CmdFileScanner scanner;
	if( ! scanner.scanForFiles( params.cmdFilePath ) )
	{
		cout << "Could not locate any files in path \"" << params.cmdFilePath << "\"." << endl;
		return false;
	}
	else if( ! scanner.parseFiles( ) )
	{
		cout << "Error parsing files in path \"" << params.cmdFilePath << "\"" << endl;
		return false;
	}

	scanner.writeCmdIncludeFile( params.cmdIncludeFile );
	scanner.writeCmdListfile( params.cmdListFile );

	return 0;
}