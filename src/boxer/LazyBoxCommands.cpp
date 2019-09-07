#include "LazyBoxCommands.hpp"

#include <ctime>
#include <chrono>
#include <cwctype>
#include <iostream>

#include <sys/stat.h>
#include <unistd.h>

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";
static const string NAME_MARKER = "@name";
static const string DESCRIP_MARKER = "@descrip";
static const string FUNCTION_MARKER = "@function";
static const string TEST_MARKER = "@test";
static const string TESTPARAM_MARKER = "@t_param";

LazyBoxCommand::LazyBoxCommand( string fileName, string fileContents )
{
    m_fileName = fileName;
    m_name = "";
    m_descrip = "";
    m_function = "";

    parseField( fileContents, NAME_MARKER, m_name );
    parseField( fileContents, DESCRIP_MARKER, m_descrip );
    parseField( fileContents, FUNCTION_MARKER, m_function );

    size_t location = 0;
    while( location != string::npos )
    {
        string testName;
        string parameters;
        location = parseDoubleField( fileContents, TEST_MARKER, testName, parameters, location );
        if( location != string::npos )
        {
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

bool LazyBoxCommand::isValid( )
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

bool LazyBoxCommand::getIsCPP( )
{
    return ( m_fileName.substr( m_fileName.length( ) - 3 ) == "cpp" );
}
string LazyBoxCommand::getFileName( )
{
    return m_fileName;
}
string LazyBoxCommand::getFileNameShort( )
{
    string result = m_fileName;
    size_t lastIndex = m_fileName.find_last_of( '/' );
    if( lastIndex != string::npos )
    {
        result = m_fileName.substr( lastIndex + 1 );
    }

    return result;
}
string LazyBoxCommand::getName( )
{
    return m_name;
}
string LazyBoxCommand::getDescrip( )
{
    return m_descrip;
}
string LazyBoxCommand::getFunction( )
{
    return m_function;
}
vector<LazyBoxCommandTest> LazyBoxCommand::getTests( )
{
    vector<LazyBoxCommandTest> tests;
    for( map<string, LazyBoxCommandTest>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        tests.push_back( it->second );
    }

    return tests;
}

size_t LazyBoxCommand::parseField( string fileContents, string marker, string& fieldData, int pos )
{
    size_t markerLocation = fileContents.find( marker, pos );
    if( markerLocation != string::npos )
    {
        size_t endOfLine = fileContents.find( "\n", markerLocation );
        size_t dataStart = markerLocation + marker.length( );

        fieldData = trimString( fileContents.substr( dataStart, endOfLine - dataStart ) );

        markerLocation += marker.length( );
    }

    return markerLocation;
}

size_t LazyBoxCommand::parseDoubleField( string fileContents, string marker, string& fieldName, string& fieldData, int pos )
{
    size_t markerLocation = fileContents.find( marker, pos );
    if( markerLocation != string::npos )
    {
        size_t endOfLine = fileContents.find( "\n", markerLocation );
        size_t dataStart = markerLocation + marker.length( );
        
        string fullLine = trimString( fileContents.substr( dataStart, endOfLine - dataStart ) );
        
        size_t firstSpace = fullLine.find( " " );
        if( firstSpace != string::npos )
        {
            fieldName = fullLine.substr( 0, firstSpace );
            fieldData = fullLine.substr( firstSpace + 1 );
        }  
        else
        {
            fieldName = fullLine;
            fieldData = "";
        }

        markerLocation += marker.length( );
    }

    return markerLocation;
}

string LazyBoxCommand::trimString( string data )
{
    while( ( data.length( ) > 0 ) && ( iswspace( data[ 0 ] ) ) )
    {
        data = data.substr( 1 );
    }
    while( ( data.length( ) > 0 ) && ( iswspace( data[ data.length( ) - 1 ] ) ) )
    {
        data = data.substr( 0, data.length( ) - 1 );
    }

    return data;
}

LazyBoxCommandTest::LazyBoxCommandTest( string name )
{
    m_name = name;
    m_parameters = "";
    m_output = "";
}

string LazyBoxCommandTest::getName( )
{
    return m_name;
}
string LazyBoxCommandTest::getParameters( )
{
    return m_parameters;
}

void LazyBoxCommandTest::setParameters( string parameters )
{
    m_parameters = parameters;
}