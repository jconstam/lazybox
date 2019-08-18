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
    private:
        std::vector<std::string> m_fileList;
        std::map<std::string, LazyBoxCommand> m_commands;

        void addFileTimestamp( std::ofstream& fileStream, bool cStyle = true );
};

#endif