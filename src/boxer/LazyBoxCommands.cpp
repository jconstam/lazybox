#include "LazyBoxCommands.hpp"

#include <ctime>
#include <chrono>
#include <cwctype>
#include <iostream>

#include <sys/stat.h>

using namespace std;

static const string LAZYBOX_MARKER = "LAZYBOX_COMMAND";
static const string NAME_MARKER = "@name";
static const string DESCRIP_MARKER = "@descrip";
static const string FUNCTION_MARKER = "@function";
static const string TEST_MARKER = "@test";
static const string TESTPARAM_MARKER = "@testparam";
static const string TESTOUTPUT_MARKER = "@testoutput";

LazyBoxCommand::LazyBoxCommand( string fileContents )
{
    m_name = "";
    m_descrip = "";
    m_function = "";

    parseField( fileContents, NAME_MARKER, m_name );
    parseField( fileContents, DESCRIP_MARKER, m_descrip );
    parseField( fileContents, FUNCTION_MARKER, m_function );
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

void LazyBoxCommand::parseField( string fileContents, string marker, string& fieldData )
{
    size_t markerLocation = fileContents.find( marker );
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
}

LazyBoxCommandTest::LazyBoxCommandTest( )
{
    m_name = "";
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

void LazyBoxCommandTest::setName( string name )
{
    m_name = name;
}
void LazyBoxCommandTest::setParameters( string parameters )
{
    m_parameters = parameters;
}
void LazyBoxCommandTest::setOutput( string output )
{
    m_output = output;
}