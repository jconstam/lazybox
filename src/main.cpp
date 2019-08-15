#include <iostream>

using namespace std;

#include "cmdRegistry.hpp"

int main( int argc, char* argv[] )
{
    return CommandRegistry::runCommand( argc, argv );
}