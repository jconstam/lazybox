#include <iostream>

#include "cmdRegistry.hpp"
#include "cmdList.hpp"

using namespace std;

int CommandRegistry::runCommand( int argc, char* argv[] )
{
    string command = string( argv[ 0 ] );

    size_t lastSlash = command.find_last_of( '/' );
    if( lastSlash != string::npos )
    {
        command = command.substr( lastSlash + 1 );
    }

    if( command == "lazybox" )
    {
        if( argc == 1 )
        {
            cout << "LazyBox - BusyBox's less portable, less functional cousin." << endl;
            return 0;
        }
        else
        {
            return runCommand( argc - 1, &( argv[ 1 ] ) );
        }
    }
    else if( commandList.find( command ) != commandList.end( ) )
    {
        return commandList.at( command )( argc - 1, &( argv[ 1 ] ) );
    }
    else
    {
        cout << "Could not find command \"" << command << "\"" << endl;
        return -1;
    }
}