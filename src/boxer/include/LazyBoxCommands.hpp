#ifndef LAZY_BOX_COMMANDS_HPP__
#define LAZY_BOX_COMMANDS_HPP__

#include <map>
#include <string>

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

#endif