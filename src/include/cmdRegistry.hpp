#ifndef CMD_REGISTRY_HPP__
#define CMD_REGISTRY_HPP__

#include <map>
#include <string>

#include "cmdList.hpp"
#include "cmdRegistry.hpp"

class CommandRegistry
{
    public:
        static int runCommand( CmdListBase& commands, int argc, char* argv[] );
};
#endif