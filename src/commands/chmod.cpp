/*
    LAZYBOX_COMMAND
    @name chmod
    @descrip Change the mode of one or more files.
    @function run_chmod

    @config CMD_CHMOD
    
    @test noparams
    @test oneparam 0777
 */

#include <iostream>

#include <sys/stat.h>

using namespace std;

int run_chmod( int argc, char* argv[ ] )
{
    int startIndex = 1;

    if( argc - startIndex == 0 )
    {
        cerr << "chmod: missing operand" << endl;
        cerr << "Try 'chmod --help' for more information." << endl;
        return 1;
    }
    else if( argc - startIndex == 1 )
    {
        cerr << "chmod: missing operand after ‘" << argv[ argc - 1 ] << "’" << endl;
        cerr << "Try 'chmod --help' for more information." << endl;
        return 1;
    }

    return 0;
}