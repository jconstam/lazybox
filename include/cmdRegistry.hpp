#ifndef CMD_REGISTRY_HPP__
#define CMD_REGISTRY_HPP__

#include <map>
#include <string>

#include "cmdRegistry.hpp"

class CommandRegistry
{
    public:
        static int runCommand( int argc, char* argv[] );
};
#endif