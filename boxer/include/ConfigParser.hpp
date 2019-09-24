#ifndef CONFIG_PARSER_HPP__
#define CONFIG_PARSER_HPP__

#include <string>
#include <unordered_set>

class ConfigParser
{
    public:
        ConfigParser( );

        bool ParseFile( std::string filePath );

    private:
        std::unordered_set<std::string> m_configFlags;

        void readConfigFile( std::string fileContents );
};

#endif