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

    @test singleFileLineNumsNonBlank1
    @t_param singleFileLineNumsNonBlank1 -n catTest3
    @t_output singleFileLineNumsNonBlank1 "     1  Sixth\n     2  \n     3  Seventh\n     4  Eighth\n"

    @test singleFileLineNumsNonBlank2
    @t_param singleFileLineNumsNonBlank2 -b catTest3
    @t_output singleFileLineNumsNonBlank2 "     1  Sixth\n\n     2  Seventh\n     3  Eighth\n"
    
    @test multiFile1
    @t_param multiFile1 catTest1 catTest2
    @t_output multiFile1 First\nSecond\nThirdFourth\nFifth\n

    @test multiFileLineNums1
    @t_param multiFileLineNums1 -n catTest1 catTest2
    @t_output multiFileLineNums1 "     1  First\n     2  Second\n     3  Third     1  Fourth\n     2  Fifth\n"

    @test multiFileLineNums2
    @t_param multiFileLineNums2 -n catTest1 catTest2 catTest3
    @t_output multiFileLineNums2 "     1  First\n     2  Second\n     3  Third     1  Fourth\n     2  Fifth\n     1  Sixth\n     2  \n     3  Seventh\n     4  Eighth\n"

    @test multiFileLineNums3
    @t_param multiFileLineNums3 -b catTest1 catTest2 catTest3
    @t_output multiFileLineNums3 "     1  First\n     2  Second\n     3  Third     1  Fourth\n     2  Fifth\n     1  Sixth\n\n     2  Seventh\n     3  Eighth\n"
    
    @test singleFileShowEnds1
    @t_param singleFileShowEnds1 -E catTest1
    @t_output singleFileShowEnds1 First$\nSecond$\nThird
    
    @test singleFileShowEnds2
    @t_param singleFileShowEnds2 -E catTest2
    @t_output singleFileShowEnds2 Fourth$\nFifth$\n
    
    @test singleFileSqueeze1
    @t_param singleFileSqueeze1 -s catTest1
    @t_output singleFileSqueeze1 First\nSecond\nThird
    
    @test singleFileSqueeze2
    @t_param singleFileSqueeze2 -s catTest3
    @t_output singleFileSqueeze2 Sixth\nSeventh\nEighth\n
 */

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#include <sys/stat.h>

#include "parseArgs.h"

using namespace std;

#define PARAM_COUNT     ( 4U )

typedef struct
{
    bool numberOutputLines;
    bool numberNonBlankLines;
    bool showEnds;
    bool squeezeBlank;
} CAT_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'n', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberOutputLines ) },
    { 'b', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberNonBlankLines ) },
    { 'E', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showEnds ) },
    { 's', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, squeezeBlank ) }
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
    CAT_PARAMS params = { false, false, false, false };

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
        bool startOfLine = true;
        string fileContents = readEntireFile( filePath );
        for( size_t fileIndex = 0U; fileIndex < fileContents.length( ); fileIndex++ )
        {
            if( startOfLine )
            {
                if( params.squeezeBlank )
                {
                    while( fileContents[ fileIndex ] == '\n' )
                    {
                        fileIndex++;
                        if( fileIndex >= fileContents.length( ) )
                        {
                            break;
                        }
                    }

                    if( fileIndex >= fileContents.length( ) )
                    {
                        break;
                    }
                }

                if( params.numberOutputLines )
                {
                    NumberLine( lineNumber++ );
                }
                else if( params.numberNonBlankLines )
                {
                    if( fileContents[ fileIndex ] != '\n' )
                    {
                        NumberLine( lineNumber++ );
                    }
                }
                startOfLine = false;
            }
            
            if( fileContents[ fileIndex ] == '\n' )
            {
                if( params.showEnds )
                {
                    cout << "$";
                }
                startOfLine = true;
            }

            cout << fileContents[ fileIndex ];
        }
    }

    return 0;
}