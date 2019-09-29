#ifndef CONFIG_PARSER_HPP__
#define CONFIG_PARSER_HPP__

#include <string>
#include <unordered_set>

class ConfigParser
{
    public:
        ConfigParser( );

        bool ParseFile( std::string filePath );
        bool IsInConfig( std::string configFlag );

        static void GenerateFile( std::string filePath, std::unordered_set<std::string> configFlags );

        std::unordered_set<std::string> GetConfigFlags( );
    private:
        std::unordered_set<std::string> m_configFlags;

        void readConfigFile( std::string fileContents );
};

#endif