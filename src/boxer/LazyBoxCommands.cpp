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
static const string TESTOUTPUT_MARKER = "@t_output";

LazyBoxCommand::LazyBoxCommand( string fileContents )
{
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
        location = parseField( fileContents, TEST_MARKER, testName, location );
        if( location != string::npos )
        {
            map<string,LazyBoxCommandTest>::iterator it = m_tests.find( testName );
            if( it == m_tests.end( ) )
            {
                LazyBoxCommandTest test( testName );
                m_tests[ testName ] = test;
            }

            location += TEST_MARKER.length( );
        }
    }

    location = 0;
    while( location != string::npos )
    {
        string testParam;
        location = parseField( fileContents, TESTPARAM_MARKER, testParam, location );
        if( location != string::npos )
        {
            int start = location + TESTPARAM_MARKER.length( );
            while( iswspace( fileContents[ start ] ) )
            {
                start++;
            }
            int nextNewLine = fileContents.find( "\n", start );
            int nextSpace = fileContents.find( " ", start );

            if( nextSpace < nextNewLine )
            {
                string testName = fileContents.substr( start, nextSpace - start );
                string params = fileContents.substr( nextSpace, nextNewLine - nextSpace );

                cout << "TEST: \"" << testName << "\" - PARAMS: \"" << params << "\""<< endl;
            }
            location = nextNewLine + 1;
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

size_t LazyBoxCommand::parseField( string fileContents, string marker, string& fieldData, int pos )
{
    size_t markerLocation = fileContents.find( marker, pos );
    if( markerLocation != string::npos )
    {
        size_t endOfLine = fileContents.find( "\n", markerLocation );
        size_t dataStart = markerLocation + marker.length( );

        fieldData = fileContents.substr( dataStart, endOfLine - dataStart );
        while( iswspace( fieldData[ 0 ] ) )
        {
            fieldData = fieldData.substr( 1 );
        }
        while( iswspace( fieldData[ fieldData.length( ) - 1 ] ) )
        {
            fieldData = fieldData.substr( 0, fieldData.length( ) - 1 );
        }
    }

    return markerLocation;
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
string LazyBoxCommandTest::getOutput( )
{
    return m_output;
}

void LazyBoxCommandTest::setParameters( string parameters )
{
    m_parameters = parameters;
}
void LazyBoxCommandTest::setOutput( string output )
{
    m_output = output;
}