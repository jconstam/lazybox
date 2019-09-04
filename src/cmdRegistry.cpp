#include <iostream>

#include "cmdRegistry.hpp"

using namespace std;

int CommandRegistry::runCommand( CmdListBase& commands, int argc, char* argv[] )
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
            return runCommand( commands, argc - 1, &( argv[ 1 ] ) );
        }
    }
    else 
    {
        CmdFunc commandFunction = commands.getFunction( command );
        if( commandFunction != nullptr )
        {
            return commandFunction( argc, &( argv[ 0 ] ) );
        }
        else
        {
            cout << "Could not find command \"" << command << "\"" << endl;
            return 1;
        }
    }
}