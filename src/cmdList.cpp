#include "cmdList.hpp"

const std::map<std::string, CmdFunc> commandList = 
{
    { "echo", run_echo },
    { "date", run_date }
};