#include <iostream>
#include <getopt.h>

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