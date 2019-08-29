#ifndef LAZY_BOX_COMMANDS_HPP__
#define LAZY_BOX_COMMANDS_HPP__

#include <map>
#include <vector>
#include <string>

class LazyBoxCommandTest
{
    public:
        LazyBoxCommandTest( std::string name = "" );

        std::string getName( );
        std::string getParameters( );
        std::string getOutput( );

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
        LazyBoxCommand( std::string fileName = "", std::string fileContents = "" );

        bool isValid( );

        bool getIsCPP( );
        std::string getFileName( );
        std::string getFileNameShort( );
        std::string getName( );
        std::string getDescrip( );
        std::string getFunction( );
        std::vector<LazyBoxCommandTest> getTests( );
    private:
        std::string m_fileName;
        std::string m_name;
        std::string m_descrip;
        std::string m_function;
        std::map<std::string,LazyBoxCommandTest> m_tests;

        size_t parseField( std::string fileContents, std::string marker, std::string& fieldData, int pos = 0 );
        size_t parseDoubleField( std::string fileContents, std::string marker, std::string& fieldName, std::string& fieldData, int pos = 0 );

        std::string trimString( std::string data );
};

#endif