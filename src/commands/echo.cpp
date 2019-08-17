/*
    LAZYBOX_COMMAND
    @name echo
    @descrip Echos a string back  
    @function run_echo
 */

#include <iostream>

using namespace std;

int run_echo( int argc, char* argv[ ] )
{
    for( int i = 0; i < argc; i++ )
    {
        cout << argv[ i ];
        if( i < argc - 1 )
        {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}