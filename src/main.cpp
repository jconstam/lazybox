#include <iostream>

using namespace std;

#include "echo.hpp"

int main( int argc, char* argv[] )
{
    cout << "Hello World." << endl;

    run_echo( argc, argv );

    return 0;
}