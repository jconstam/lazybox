#include "LazyBoxCommands.hpp"

#include <ctime>
#include <chrono>
#include <cwctype>
#include <iostream>

#include <sys/stat.h>
#include <unistd.h>

#include "FileCommon.hpp"

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";
static const string NAME_MARKER = "@name";
static const string DESCRIP_MARKER = "@descrip";
static const string FUNCTION_MARKER = "@function";
static const string TEST_MARKER = "@test";
static const string CONFIG_MARKER = "@config";

LazyBoxCommandTest::LazyBoxCommandTest( const string& name ): m_name( name ), m_parameters( "" )
{
    
}

string LazyBoxCommandTest::getName( ) const
{
    return m_name;
}
string LazyBoxCommandTest::getParameters( ) const
{
    return m_parameters;
}

void LazyBoxCommandTest::setParameters( const string& parameters )
{
    m_parameters = parameters;
}

LazyBoxCommand::LazyBoxCommand( const string& fileName, const string& fileContents ): m_fileName( fileName ), m_name( "" ), m_descrip( "" ), m_function( "" )
{
    parseField( fileContents, NAME_MARKER, m_name );
    parseField( fileContents, DESCRIP_MARKER, m_descrip );
    parseField( fileContents, FUNCTION_MARKER, m_function );
    parseField( fileContents, CONFIG_MARKER, m_config );

    size_t location = 0;
    while( location != string::npos )
    {
        vector<string> testFields;
        location = parseFields( fileContents, TEST_MARKER, testFields, 2U, location );
        if( location != string::npos )
        {
            string testName = testFields[ 0 ];
            string parameters = testFields[ 1 ];

            map<string,LazyBoxCommandTest>::iterator it = m_tests.find( testName );
            if( it == m_tests.end( ) )
            {
                LazyBoxCommandTest test( testName );
                test.setParameters( parameters );
                m_tests[ testName ] = test;
            }
        }
    }
}

bool LazyBoxCommand::isValid( ) const
{
    if( m_name == "" )
    {
        return false;
    }
    else if( m_descrip == "" )
    {
        return false;
    }
    else if( m_function == "" )
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool LazyBoxCommand::getIsCPP( ) const
{
    return ( m_fileName.substr( m_fileName.length( ) - 3 ) == "cpp" );
}
string LazyBoxCommand::getFileNameShort( ) const
{
    string result = m_fileName;
    size_t lastIndex = m_fileName.find_last_of( '/' );
    if( lastIndex != string::npos )
    {
        result = m_fileName.substr( lastIndex + 1 );
    }

    return result;
}
string LazyBoxCommand::getName( ) const
{
    return m_name;
}
string LazyBoxCommand::getFunction( ) const
{
    return m_function;
}
string LazyBoxCommand::getConfig( ) const
{
    return m_config;
}
vector<LazyBoxCommandTest> LazyBoxCommand::getTests( )
{
    vector<LazyBoxCommandTest> tests;
    for( map<string, LazyBoxCommandTest>::iterator it = m_tests.begin(); it != m_tests.end(); it = next( it ) )
    {
        tests.push_back( it->second );
    }

    return tests;
}

size_t LazyBoxCommand::parseField( const string& fileContents, const string& marker, string& field, int pos )
{
    vector<string> fields;
    size_t result = parseFields( fileContents, marker, fields, 1, pos );
    if( result != string::npos && fields.size( ) > 0 )
    {
        field = fields[ 0 ];
    }

    return result;
}

size_t LazyBoxCommand::parseFields( const string& fileContents, const string& marker, vector<string>& fields, int fieldCount, int pos )
{
    size_t markerLocation = fileContents.find( marker, pos );
    if( markerLocation != string::npos )
    {
        size_t endOfLine = fileContents.find( "\n", markerLocation );
        size_t dataStart = markerLocation + marker.length( );

        string fullLine = FileCommon::trimString( fileContents.substr( dataStart, endOfLine - dataStart ) );
        if( fieldCount == 1 )
        {
            fields.push_back( fullLine );
        }
        else
        {
            size_t start = 0;
            for( int i = 0; i < fieldCount - 1; i++ )
            {
                size_t nextSpace = fullLine.find( " ", start );
                if( nextSpace == string::npos )
                {
                    fields.push_back( fullLine.substr( start, endOfLine - start ) );
                }
                else
                {
                    fields.push_back( fullLine.substr( start, nextSpace ) );
                }
                start = nextSpace + 1;
            }
            
            fields.push_back( FileCommon::trimString( fullLine.substr( start, endOfLine - start ) ) );
        }

        markerLocation += marker.length( );
    }

    return markerLocation;
}
