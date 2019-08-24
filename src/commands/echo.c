/*
    LAZYBOX_COMMAND
    @name echo
    @descrip Echos a string back  
    @function run_echo

    @test nothing
    @t_param nothing
    @t_output nothing \n

    @test one
    @t_param one testing
    @t_output one testing\n

    @test many
    @t_param many this is a lot of parameters and some are numbers 1 2 3
    @t_output many this is a lot of parameters and some are numbers 1 2 3\n

    @test one_nonewline
    @t_param one_nonewline -n testing
    @t_output one_nonewline testing

    @test many_nonewline
    @t_param many_nonewline -n this is a lot of parameters and some are numbers 1 2 3
    @t_output many_nonewline this is a lot of parameters and some are numbers 1 2 3
 */

#include <stdio.h>

#include "parseArgs.h"

#define PARAM_COUNT     ( 3U )

typedef struct
{
    bool noNewline;
    bool interpEscapes;
    bool dontInterpEscapes;
} ECHO_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'n', false, ARG_DATA_TYPE_BOOL, offsetof( ECHO_PARAMS, noNewline ) },
    { 'e', false, ARG_DATA_TYPE_BOOL, offsetof( ECHO_PARAMS, interpEscapes ) },
    { 'E', false, ARG_DATA_TYPE_BOOL, offsetof( ECHO_PARAMS, dontInterpEscapes ) }
};

int run_echo( int argc, char* argv[ ] )
{
    int startIndex;
    ECHO_PARAMS params = { false, false, false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return -1;
    }

    if( params.dontInterpEscapes )
    {
        params.interpEscapes = false;
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