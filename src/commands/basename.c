/*
    LAZYBOX_COMMAND
    @name basename
    @descrip Strip directory path and .suffix from file name.
    @function run_basename
    
    @test noFile
    @t_param noFile
    @t_output noFile basename: missing operand\n

    @test singleFile
    @t_param singleFile /path/to/the/file.ext
    @t_output singleFile file.ext\n

    @test singleFileWithExt
    @t_param singleFileWithExt /path/to/the/file.ext .ext
    @t_output singleFileWithExt file\n
    
    @test singleFileWithExtWrong
    @t_param singleFileWithExtWrong /path/to/the/file.ext .ext2
    @t_output singleFileWithExtWrong file.ext\n

    @test singleFolder
    @t_param singleFolder /path/to/the/folder/
    @t_output singleFolder folder\n

    @test singleFolderWithExt
    @t_param singleFolderWithExt /path/to/the/folder/ .ext
    @t_output singleFolderWithExt folder\n
*/

#include <stdio.h>
#include <string.h>

#include "parseArgs.h"

#define PARAM_COUNT     ( 1U )

typedef struct
{
    bool removeSuffix;
} BASENAME_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 's', false, ARG_DATA_TYPE_BOOL, offsetof( BASENAME_PARAMS, removeSuffix ) }
};

static void printBaseName( char* path, char* removeSuffix )
{
    char* last = NULL;

    char* token = strtok( path, "/" );
    while( token != NULL )
    {
        last = token;
        token = strtok( NULL, "/" );
    }

    if( removeSuffix != NULL )
    {
        int lastSize = strlen( last );
        int suffixSize = strlen( removeSuffix );
        if( strcmp( &( last[ lastSize - suffixSize ] ), removeSuffix ) == 0 )
        {
            last[ lastSize - suffixSize ] = '\0';
        }
    }

    printf( "%s\n", last );
}

int run_basename( int argc, char* argv[ ] )
{
    int startIndex;
    BASENAME_PARAMS params = { false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    if( startIndex >= argc )
    {
        printf( "basename: missing operand\n" );
        return 1;
    }

    char* suffix = NULL;
    if( argv[ argc - 1 ][ 0 ] == '.' )
    {
        suffix = argv[ argc - 1 ];
    }

    printBaseName( argv[ startIndex ], suffix );

    return 0;
}