#ifndef CMD_LIST_HPP__
#define CMD_LIST_HPP__

#include <map>

#include "commands.hpp"

typedef int ( *CmdFunc )( int, char** );

extern const std::map<std::string, CmdFunc> commandList;

#endif