/*
    LAZYBOX_COMMAND
    @name cat
    @descrip Concatenate file(s) and print them to standard out.
    @function run_cat
 */

#include <string>
#include <fstream>
#include <iostream>

#include <sys/stat.h>

#include "parseArgs.h"

using namespace std;

#define PARAM_COUNT     ( 1U )

typedef struct
{
    bool numberOutputLines;
} CAT_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'n', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberOutputLines ) }
};

static string readEntireFile( string filePath )
{
    ifstream fileStream( filePath );
    string fileContents;

    fileStream.seekg( 0, ios::end );   
    fileContents.reserve( fileStream.tellg( ) );
    fileStream.seekg( 0, ios::beg );

    fileContents.assign( istreambuf_iterator<char>( fileStream ), istreambuf_iterator<char>( ) );

    return fileContents;
}

int run_cat( int argc, char* argv[ ] )
{
    int startIndex;
    CAT_PARAMS params = { false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    int fileIndex;
    for( fileIndex = startIndex; fileIndex < argc; fileIndex++ )
    {
        string filePath = argv[ fileIndex ];

        struct stat buffer;   
        if( stat( filePath.c_str( ), &( buffer ) ) != 0 )
        {
            cout << "cat: " << filePath << ": No such file or directory" << endl;
            return 1;
        }

        int lineNumber = 1;
        int stringIndex = 0;
        string fileContents = readEntireFile( filePath );
        while( ( size_t ) stringIndex < fileContents.length( ) )
        {
            int nextStringIndex = fileContents.find( "\n", stringIndex );

            if( params.numberOutputLines )
            {
                cout.width( 6 );
                cout << right << lineNumber++ << "  ";
            }
            cout << fileContents.substr( stringIndex, nextStringIndex - stringIndex ) << endl;

            stringIndex = nextStringIndex + 1;
        }
    }

    return 0;
}