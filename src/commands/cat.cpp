/*
    LAZYBOX_COMMAND
    @name cat
    @descrip Concatenate file(s) and print them to standard out.
    @function run_cat
    
    @test singleFile1
    @t_param singleFile1 catTest1
    @t_output singleFile1 First\nSecond\nThird
    
    @test singleFile2
    @t_param singleFile2 catTest2
    @t_output singleFile2 Fourth\nFifth\n

    @test singleFileLineNums
    @t_param singleFileLineNums -n catTest1
    @t_output singleFileLineNums "     1  First\n     2  Second\n     3  Third"
    
    @test multiFile1
    @t_param multiFile1 catTest1 catTest2
    @t_output multiFile1 First\nSecond\nThirdFourth\nFifth\n

    @test multiFileLineNums
    @t_param multiFileLineNums -n catTest1 catTest2
    @t_output multiFileLineNums "     1  First\n     2  Second\n     3  Third     1  Fourth\n     2  Fifth\n"
 */

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#include <sys/stat.h>

#include "parseArgs.h"

using namespace std;

#define PARAM_COUNT     ( 2U )

typedef struct
{
    bool numberOutputLines;
    bool numberNonBlankLines;
} CAT_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'n', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberOutputLines ) },
    { 'b', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberNonBlankLines ) }
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

static void NumberLine( int lineNumber )
{
    cout.width( 6 );
    cout << right << lineNumber << "  ";
}

int run_cat( int argc, char* argv[ ] )
{
    int startIndex;
    CAT_PARAMS params = { false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    if( params.numberNonBlankLines )
    {
        params.numberOutputLines = false;
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
        string fileContentsString = readEntireFile( filePath );
        char* fileContents = new char[ fileContentsString.length( ) + 1U ];
        memset( fileContents, 0, fileContentsString.length( ) + 1U );
        strncpy( fileContents, fileContentsString.c_str( ), fileContentsString.length( ) );

        bool endsWithNewLine = ( fileContentsString[ fileContentsString.length( ) - 1U ] == '\n' );

        char* currToken = strtok( fileContents, "\n" );
        while( currToken != nullptr )
        {
            if( params.numberOutputLines )
            {
                NumberLine( lineNumber );
            }
            string currLine( currToken );

            currToken = strtok( NULL, "\n" );

            cout << currLine;
            if( currToken == nullptr )
            {
                if( endsWithNewLine )
                {
                    cout << endl;
                }
            }
            else
            {
                cout << endl;
            }

            lineNumber++;
        }

        delete[ ] fileContents;
    }

    return 0;
}