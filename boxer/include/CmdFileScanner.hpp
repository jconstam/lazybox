#ifndef CMD_FILE_SCANNER_HPP__
#define CMD_FILE_SCANNER_HPP__

#include <map>
#include <string>
#include <vector>
#include <fstream>

#include "LazyBoxCommands.hpp"

class CmdFileScanner
{
    public:
        CmdFileScanner( );

        bool scanForFiles( std::string path );
        bool parseFiles( );
        void writeCmdIncludeFile( std::string includeFilePath );
        void writeCmdListfile( std::string listFilePath );
        void writeSymlinkScriptfile( std::string scriptFilePath );
        void writeCMakeTestfile( std::string testFilePath );
        void writeCMakeCommandsFile( std::string commandsFilePath );
    private:
        std::vector<std::string> m_fileList;
        std::map<std::string, LazyBoxCommand> m_commands;

        void writeTestToCmakeTestFile( std::stringstream& fileStream, LazyBoxCommand command, LazyBoxCommandTest test, std::string testFilePath );
        void addFileHeader( std::stringstream& fileStream, bool cStyle = true );
        void writeFileIfChanged( std::string filePath, std::string contents );
};

#endif