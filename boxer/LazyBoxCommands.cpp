#include "LazyBoxCommands.hpp"

#include <ctime>
#include <chrono>
#include <cwctype>
#include <iostream>

#include <sys/stat.h>
#include <unistd.h>

#include "FileCommon.hpp"
#include "StringCommon.hpp"

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";
static const string NAME_MARKER = "@name";
static const string DESCRIP_MARKER = "@descrip";
static const string FUNCTION_MARKER = "@function";
static const string TEST_MARKER = "@test";
static const string TEST_TYPE_DIFF_MARKER = "diff";
static const string CONFIG_MARKER = "@config";

LazyBoxCommandTest::LazyBoxCommandTest( const string& name, const string& type ): m_name( name ), m_parameters( "" )
{
    if( type == TEST_TYPE_DIFF_MARKER )
    {
        m_type = LAZYBOX_COMMAND_TEST_TYPE_DIFF;
    }
    else
    {
        throw "Unknown test type " + type;
    }
}

string LazyBoxCommandTest::getName( ) const
{
    return m_name;
}
string LazyBoxCommandTest::getParameters( ) const
{
    return m_parameters;
}
LAZYBOX_COMMAND_TEST_TYPE LazyBoxCommandTest::getType( ) const
{
    return m_type;
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
        location = parseFields( fileContents, TEST_MARKER, testFields, 3U, location );
        if( location != string::npos )
        {
            string testType = testFields[ 0 ];
            string testName = testFields[ 1 ];
            string parameters = testFields[ 2 ];

            map<string,LazyBoxCommandTest>::iterator it = m_tests.find( testName );
            if( it == m_tests.end( ) )
            {
                LazyBoxCommandTest test( testName, testType );
                test.setParameters( parameters );
                m_tests.insert( { testName, test } );
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

        string fullLine = StringCommon::trim( fileContents.substr( dataStart, endOfLine - dataStart ) );

        vector<string> lineParts = StringCommon::split( fullLine, ' ' );
        for( int i = 0; i < fieldCount - 1; i++ )
        {
            fields.push_back( lineParts[ i ] );
        }
        string lastPart = "";
        for( uint32_t i = fieldCount - 1U; i < lineParts.size( ); i++ )
        {
            lastPart += lineParts[ i ] + " ";
        }
        fields.push_back( StringCommon::trim( lastPart ) );

        markerLocation = endOfLine + 1U;
    }

    return markerLocation;
}
