#ifndef CMD_FILE_SCANNER_HPP__
#define CMD_FILE_SCANNER_HPP__

#include <map>
#include <string>
#include <vector>
#include <fstream>

#include "LazyBoxCommands.hpp"
#include "ConfigParser.hpp"

class CmdFileScanner
{
    public:
        CmdFileScanner( );

        bool scanForFiles( std::string& path );
        bool parseFiles( ConfigParser& parser );
        void writeCmdIncludeFile( std::string& includeFilePath );
        void writeCmdListfile( std::string& listFilePath );
        void writeSymlinkScriptfile( std::string& scriptFilePath );
        void writeCMakeTestfile( std::string& testFilePath );
        void writeCMakeCommandsFile( std::string& commandsFilePath );
    private:
        std::vector<std::string> m_fileList;
        std::map<std::string, LazyBoxCommand> m_commands;

        static void writeTestToCmakeTestFile( std::stringstream& output, const LazyBoxCommand& command, const LazyBoxCommandTest& test, const std::string& testFilePath );
        static void addFileHeader( std::stringstream& output, bool cStyle = true );
        static void writeFileIfChanged( std::string& filePath, std::stringstream& contents );
};

#endif