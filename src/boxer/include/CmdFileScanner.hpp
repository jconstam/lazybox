#ifndef CMD_FILE_SCANNER_HPP__
#define CMD_FILE_SCANNER_HPP__

#include <map>
#include <string>
#include <vector>
#include <fstream>

class LazyBoxCommandTest
{
    public:
        LazyBoxCommandTest( );

        std::string getName( );
        std::string getParameters( );
        std::string getOutput( );

        void setName( std::string name );
        void setParameters( std::string parameters );
        void setOutput( std::string output );
    private:
        std::string m_name;
        std::string m_parameters;
        std::string m_output;
};

class LazyBoxCommand
{
    public:
        LazyBoxCommand( std::string fileContents = "" );

        bool isValid( );

        std::string getName( );
        std::string getDescrip( );
        std::string getFunction( );
    private:
        std::string m_name;
        std::string m_descrip;
        std::string m_function;
        std::map<std::string,LazyBoxCommandTest> m_tests;

        void parseField( std::string fileContents, std::string marker, std::string& fieldData );
};

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