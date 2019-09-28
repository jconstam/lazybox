#ifndef CMD_LIST_HPP__
#define CMD_LIST_HPP__

#include <map>

#include "commands.hpp"

typedef int ( *CmdFunc )( int, char** );

class CmdListBase
{
    public:
        virtual ~CmdListBase( ) { };
        virtual CmdFunc getFunction( std::string funcName ) = 0;
};

class CmdList : public CmdListBase
{
    private:
        static const std::map<std::string, CmdFunc> commandList;
    
    public:
        CmdList( ) { }
        CmdFunc getFunction( std::string funcName )
        {
            if( commandList.find( funcName ) != commandList.end( ) )
            {
                return commandList.at( funcName );
            }
            else
            {
                return nullptr;
            }
        }
};

#endif