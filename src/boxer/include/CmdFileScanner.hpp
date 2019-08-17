#ifndef CMD_FILE_SCANNER_HPP__
#define CMD_FILE_SCANNER_HPP__

#include <string>
#include <vector>

class LazyBoxCommand
{
    public:
        LazyBoxCommand( std::string fileContents );

        bool isValid( );

        std::string getName( );
        std::string getDescrip( );
        std::string getFunction( );
    private:
        std::string m_name;
        std::string m_descrip;
        std::string m_function;

        void parseField( std::string fileContents, std::string marker, std::string& fieldData );
};

class CmdFileScanner
{
    public:
        CmdFileScanner( );

        bool scanForFiles( std::string path );
        bool parseFiles( );
        void writeCmdIncludeFile( std::string includeFilePath );
    private:
        std::vector<std::string> m_fileList;
        std::vector<LazyBoxCommand> m_cmdList;
};

#endif