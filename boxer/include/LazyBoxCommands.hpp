#ifndef LAZY_BOX_COMMANDS_HPP__
#define LAZY_BOX_COMMANDS_HPP__

#include <map>
#include <vector>
#include <string>

class LazyBoxCommandTest
{
    public:
        explicit LazyBoxCommandTest( const std::string& name = "" );

        std::string getName( ) const;
        std::string getParameters( ) const;

        void setParameters( const std::string& parameters );
    private:
        std::string m_name;
        std::string m_parameters;
};

class LazyBoxCommand
{
    public:
        LazyBoxCommand( const std::string& fileName = "", const std::string& fileContents = "" );

        bool isValid( ) const;

        bool getIsCPP( ) const;
        std::string getFileNameShort( ) const;
        std::string getName( ) const;
        std::string getFunction( ) const;
        std::string getConfig( ) const;
        std::vector<LazyBoxCommandTest> getTests( );
    private:
        std::string m_fileName;
        std::string m_name;
        std::string m_descrip;
        std::string m_function;
        std::string m_config;
        std::map<std::string,LazyBoxCommandTest> m_tests;

        static size_t parseField( const std::string& fileContents, const std::string& marker, std::string& fieldData, int pos = 0 );
        static size_t parseDoubleField( const std::string& fileContents, const std::string& marker, std::string& fieldName, std::string& fieldData, int pos = 0 );
};

#endif