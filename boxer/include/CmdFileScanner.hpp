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
        void writeCmdIncludeFile( const std::string& includeFilePath );
        void writeCmdListfile( const std::string& listFilePath );
        void writeSymlinkScriptfile( const std::string& scriptFilePath );
        void writeCMakeTestfile( const std::string& testFilePath );
        void writeCMakeCommandsFile( const std::string& commandsFilePath );
    private:
        std::vector<std::string> m_fileList;
        std::map<std::string, LazyBoxCommand> m_commands;

        static void writeTestToCmakeTestFile( std::stringstream& output, const LazyBoxCommand& command, const LazyBoxCommandTest& test, const std::string& testFilePath );
        static void writeDiffTestToCmakeTestFile( std::stringstream& output, const LazyBoxCommand& command, const LazyBoxCommandTest& test, const std::string& execPath );
        static void addFileHeader( std::stringstream& output, bool cStyle = true );
        static void writeFileIfChanged( const std::string& filePath, std::stringstream& contents );
};

#endif