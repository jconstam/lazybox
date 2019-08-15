#include <iostream>

using namespace std;

#include "echo.hpp"

int main( int argc, char* argv[] )
{
    cout << "COUNT: " << argc << " \"";
    for( int i = 0; i < argc; i++ )
    {
        cout << argv[ i ];
        if( i < argc - 1 )
        {
            cout << " ";
        }
    }
    cout << "\"" << endl;

    run_echo( argc, argv );

    return 0;
}