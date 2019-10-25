#include "StringCommon.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

string StringCommon::trim( string raw )
{
    while( ( raw.length( ) > 0 ) && ( isspace( raw[ 0 ] ) ) )
    {
        raw = raw.substr( 1 );
    }
    while( ( raw.length( ) > 0 ) && ( isspace( raw[ raw.length( ) - 1U ] ) ) )
    {
        raw = raw.substr( 0, raw.length( ) - 1U );
    }

    return raw;
}

string StringCommon::removeWhitespace( string raw )
{
    string output = "";
    for( size_t i = 0U; i < raw.length( ); i++ )
    {
        if( !isspace( raw[ i ] ) )
        {
            output += raw[ i ];
        }
    }

    return output;
}

vector<string> StringCommon::split( const string& input, const char delimiter )
{
    string token;
    vector<string> output;
    stringstream stream( input );
    while( getline( stream, token, delimiter ) )
    {
        if( ( token != "" ) && ( token != string( 1, delimiter ) ) )
        {
            output.push_back( token );
        }
    }

    return output;
}