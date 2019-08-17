#ifndef CMD_FILE_SCANNER_HPP__
#define CMD_FILE_SCANNER_HPP__

#include <string>
#include <vector>

class CmdFileScanner
{
    public:
        CmdFileScanner( );

        bool scanForFiles( std::string path );
        bool parseFiles( );
    private:
        std::vector<std::string> m_fileList;
};

class LazyBoxCommand
{
    public:
        LazyBoxCommand( );

        void setName( std::string name );
        void setDescrip( std::string descrip );
        void setFunction( std::string function );
    private:
        std::string m_name;
        std::string m_descrip;
        std::string m_function;
};

#endif