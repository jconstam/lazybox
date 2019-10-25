/*
    LAZYBOX_COMMAND
    @name cat
    @descrip Concatenate file(s) and print them to standard out.
    @function run_cat

    @config CMD_CAT
    
    @test diff singleFile1 ${COMMAND_TEST_ROOT}/cat/test1
    @test diff singleFile2 ${COMMAND_TEST_ROOT}/cat/test2
    @test diff singleFileLineNums -n ${COMMAND_TEST_ROOT}/cat/test1
    @test diff singleFileLineNumsNonBlank1 -n ${COMMAND_TEST_ROOT}/cat/test3
    @test diff singleFileLineNumsNonBlank2 -b ${COMMAND_TEST_ROOT}/cat/test3
    @test diff multiFile1 ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2
    @test diff multiFileLineNums1 -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2
    @test diff multiFileLineNums2 -n ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3
    @test diff multiFileLineNums3 -b ${COMMAND_TEST_ROOT}/cat/test1 ${COMMAND_TEST_ROOT}/cat/test2 ${COMMAND_TEST_ROOT}/cat/test3
    @test diff singleFileShowEnds1 -E ${COMMAND_TEST_ROOT}/cat/test1
    @test diff singleFileShowEnds2 -E ${COMMAND_TEST_ROOT}/cat/test2
    @test diff singleFileSqueeze1 -s ${COMMAND_TEST_ROOT}/cat/test1
    @test diff singleFileSqueeze2 -s ${COMMAND_TEST_ROOT}/cat/test3
    @test diff singleFileShowTabs1 -T ${COMMAND_TEST_ROOT}/cat/test1
    @test diff singleFileShowTabs2 ${COMMAND_TEST_ROOT}/cat/test4
    @test diff singleFileShowTabs3 -T ${COMMAND_TEST_ROOT}/cat/test4
    @test diff singleFileShowNonPrintable1 -v ${COMMAND_TEST_ROOT}/cat/test5
    @test diff singleFileShowAll1 -A ${COMMAND_TEST_ROOT}/cat/test4
    @test diff singleFileShowAll2 -A ${COMMAND_TEST_ROOT}/cat/test5
    @test diff singleFileShowAllNoTabs1 -e ${COMMAND_TEST_ROOT}/cat/test4
    @test diff singleFileShowAllNoTabs2 -e ${COMMAND_TEST_ROOT}/cat/test5
    @test diff singleFileShowAllNoEnds1 -t ${COMMAND_TEST_ROOT}/cat/test4
    @test diff singleFileShowAllNoEnds2 -t ${COMMAND_TEST_ROOT}/cat/test5
 */

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#include <sys/stat.h>

#include "parseArgs.h"

using namespace std;

#define PARAM_COUNT         ( 9U )
#define MIN_PRINTABLE_CHAR  ( ' ' )
#define MAX_PRINTABLE_CHAR  ( '~' )

typedef struct
{
    bool numberOutputLines;
    bool numberNonBlankLines;
    bool showEnds;
    bool squeezeBlank;
    bool showTabs;
    bool showNonPrintable;
    bool showAll;
    bool showAllNoTabs;
    bool showAllNoEnds;
} CAT_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'A', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showAll ) },
    { 'b', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberNonBlankLines ) },
    { 'e', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showAllNoTabs ) },
    { 'E', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showEnds ) },
    { 'n', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, numberOutputLines ) },
    { 's', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, squeezeBlank ) },
    { 't', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showAllNoEnds ) },
    { 'T', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showTabs ) },
    { 'v', false, ARG_DATA_TYPE_BOOL, offsetof( CAT_PARAMS, showNonPrintable ) }
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
    cout << right << lineNumber << "\t";
}

static void PrintCharacter( char character, bool showTabs, bool showNonPrintable )
{
    if( ( showTabs ) && ( character == '\t' ) )
    {
        cout << "^I";
    }
    else if( ( showNonPrintable ) && ( ! isprint( character ) ) )
    {
        if( ( character == '\t' ) || ( character == '\n' ) )
        {
            cout << character;
        }
        else if( character < MIN_PRINTABLE_CHAR )
        {
            cout << "^" << character + 64;
        }
        else if( character > MAX_PRINTABLE_CHAR )
        {
            cout << "M-^" << character - 64;
        }
    }
    else
    {
        cout << character;
    }
}

int run_cat( int argc, char* argv[ ] )
{
    int startIndex;
    CAT_PARAMS params = { false, false, false, false, false, false, false, false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    if( params.numberNonBlankLines )
    {
        params.numberOutputLines = false;
    }
    if( params.showAll )
    {
        params.showNonPrintable = true;
        params.showEnds = true;
        params.showTabs = true;
    }
    if( params.showAllNoTabs )
    {
        params.showNonPrintable = true;
        params.showEnds = true;
    }
    if( params.showAllNoEnds )
    {
        params.showNonPrintable = true;
        params.showTabs = true;
    }

    int lineNumber = 1;
    bool startOfLine = true;
    for( int fileIndex = startIndex; fileIndex < argc; fileIndex++ )
    {
        string filePath = argv[ fileIndex ];

        struct stat buffer;   
        if( stat( filePath.c_str( ), &( buffer ) ) != 0 )
        {
            cout << "cat: " << filePath << ": No such file or directory" << endl;
            return 1;
        }

        string fileContents = readEntireFile( filePath );
        for( size_t byteIndex = 0U; byteIndex < fileContents.length( ); byteIndex++ )
        {
            if( startOfLine )
            {
                if( params.squeezeBlank )
                {
                    bool hasNewLine = false;
                    while( fileContents[ byteIndex ] == '\n' )
                    {
                        hasNewLine = true;
                        byteIndex++;
                        if( byteIndex >= fileContents.length( ) )
                        {
                            break;
                        }
                    }
                    
                    if( hasNewLine )
                    {
                        PrintCharacter( '\n', params.showTabs, params.showNonPrintable );
                    }
                    if( byteIndex >= fileContents.length( ) )
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
                    if( fileContents[ byteIndex ] != '\n' )
                    {
                        NumberLine( lineNumber++ );
                    }
                }
                startOfLine = false;
            }
            
            if( fileContents[ byteIndex ] == '\n' )
            {
                if( params.showEnds )
                {
                    cout << "$";
                }
                startOfLine = true;
            }

            PrintCharacter( fileContents[ byteIndex ], params.showTabs, params.showNonPrintable );
        }
    }

    return 0;
}