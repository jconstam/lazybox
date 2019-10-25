#ifndef LAZY_BOX_COMMANDS_HPP__
#define LAZY_BOX_COMMANDS_HPP__

#include <map>
#include <vector>
#include <string>

typedef enum
{
    LAZYBOX_COMMAND_TEST_TYPE_DIFF
} LAZYBOX_COMMAND_TEST_TYPE;

class LazyBoxCommandTest
{
    public:
        explicit LazyBoxCommandTest( const std::string& name = "", const std::string& type = "" );

        std::string getName( ) const;
        std::string getParameters( ) const;
        LAZYBOX_COMMAND_TEST_TYPE getType( ) const;

        void setParameters( const std::string& parameters );
    private:
        std::string m_name;
        std::string m_parameters;
        LAZYBOX_COMMAND_TEST_TYPE m_type;
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

        static size_t parseField( const std::string& fileContents, const std::string& marker, std::string& field, int pos = 0 );
        static size_t parseFields( const std::string& fileContents, const std::string& marker, std::vector<std::string>& fields, int fieldCount, int pos = 0 );
};

#endif