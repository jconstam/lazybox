#include <iostream>
#include <getopt.h>

#include "CmdFileScanner.hpp"

using namespace std;

typedef struct
{
	const char* cmdFilePath;
} BOXER_PARAMS;

static bool parseParams( int argc, char* argv[], BOXER_PARAMS* params )
{
    int opt = 0;
	while( opt != -1 )  
    {  
		opt = getopt( argc, argv, "c:" );
        switch( opt )  
        {  
            case 'c': 
				params->cmdFilePath = optarg;
				cout << "Using Command File Path \"" << params->cmdFilePath << "\"" << endl;
				break;
			case -1:
				break;
            case '?':  
			default:
				cout << "Unknown Option: " << optopt << endl;
				return false;
        }  
    }

	if( params->cmdFilePath == nullptr )
	{
		cout << "Command File Path not specified (use -c)" << endl;
		return false;
	}
	
	CmdFileScanner scanner;
	if( ! scanner.scanForFiles( params->cmdFilePath ) )
	{
		cout << "Could not locate any files in path \"" << params->cmdFilePath << "\"." << endl;
		return false;
	}
	else if( ! scanner.parseFiles( ) )
	{
		cout << "None of the files in path \"" << params->cmdFilePath << "\" are valid command files." << endl;
		return false;
	}

	return true;
}

int main( int argc, char* argv[] )
{
	BOXER_PARAMS params = { 0 };
	if( ! parseParams( argc, argv, &( params ) ) )
	{
		cout << "Could not parse command line arguments" << endl;
		return -1;
	}

	return 0;
}