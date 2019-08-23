/*
    LAZYBOX_COMMAND
    @name echo
    @descrip Echos a string back  
    @function run_echo

    @test nothing
    @t_param nothing
    @t_output nothing

    @test one
    @t_param one testing
    @t_output one testing

    @test many
    @t_param many this is a lot of parameters and some are numbers 1 2 3
    @t_output many this is a lot of parameters and some are numbers 1 2 3
 */

#include <stdio.h>

#include "parseArgs.h"

#define PARAM_COUNT     ( 1U )

typedef struct
{
    bool noNewline;
} ECHO_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'n', false, ARG_DATA_TYPE_BOOL, offsetof( ECHO_PARAMS, noNewline ) }
};

int run_echo( int argc, char* argv[ ] )
{
    int startIndex;
    ECHO_PARAMS params = { false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return -1;
    }

    for( int i = startIndex; i < argc; i++ )
    {
        printf( "%s", argv[ i ] );
        if( i < argc - 1 )
        {
            printf( " " );
        }
    }

    if( !params.noNewline )
    {
        printf( "\n" );
    }

    return 0;
}