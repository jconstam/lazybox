#include <iostream>

using namespace std;

#include "cmdList.hpp"
#include "cmdRegistry.hpp"

int main( int argc, char* argv[] )
{
    CmdList commandList;
    return CommandRegistry::runCommand( commandList, argc, argv );
}