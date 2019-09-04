/*
    LAZYBOX_COMMAND
    @name echo
    @descrip Echos a string back  
    @function run_echo
    @status In Progress
    @author Jason Constam

    @test nothing
    @t_param nothing
    @t_output nothing \n

    @test one
    @t_param one "testing"
    @t_output one "testing\n"

    @test many
    @t_param many "this is a lot of parameters and some are numbers 1 2 3"
    @t_output many "this is a lot of parameters and some are numbers 1 2 3\n"

    @test nonewline_one
    @t_param nonewline_one -n testing
    @t_output nonewline_one testing

    @test nonewline_many
    @t_param nonewline_many -n this is a lot of parameters and some are numbers 1 2 3
    @t_output nonewline_many this is a lot of parameters and some are numbers 1 2 3

    @test escape_newline1
    @t_param escape_newline1 -e testing\n
    @t_output escape_newline1 testing\n\n

    @test escape_newline2
    @t_param escape_newline2 -e -n testing\n
    @t_output escape_newline2 testing\n

    @test escape_newline3
    @t_param escape_newline3 -e testing\n\n\ntesting\ntesting
    @t_output escape_newline3 testing\n\n\ntesting\ntesting\n

    @test escape_newline4
    @t_param escape_newline4 testing\\n
    @t_output escape_newline4 testing\\n\n

    @test escape_tab1
    @t_param escape_tab1 -e testing\ttesting
    @t_output escape_tab1 testing\ttesting\n

    @test escape_tab2
    @t_param escape_tab2 -e testing\t\t\ttesting
    @t_output escape_tab2 testing\t\t\ttesting\n
 */

#include <stdio.h>
#include <string.h>

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

static void handleEscape( bool interpEscapes, char escape )
{
    if( !interpEscapes )
    {
        printf( "\\%c", escape );
    }
    else
    {
        switch( escape )
        {
            case( 'n' ):
                printf( "\n" );
                break;
            case( 't' ):
                printf( "\t" );
                break;
        }
    }
}

int run_echo( int argc, char* argv[ ] )
{
    int startIndex;
    ECHO_PARAMS params = { false, false, false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    if( params.dontInterpEscapes )
    {
        params.interpEscapes = false;
    }
    
    for( int argidx = startIndex; argidx < argc; argidx++ )
    {
        int length = strlen( argv[ argidx ] );
        for( int charIdx = 0; charIdx < length; charIdx++ )
        {
            switch( argv[ argidx ][ charIdx ] )
            {
                case( '\\' ):
                    if( charIdx < length - 1 )
                    {
                        handleEscape( params.interpEscapes, argv[ argidx ][ charIdx + 1 ] );
                        charIdx++;
                    }
                    else
                    {
                        printf( "\\" );
                    }
                    break;
                default:
                    printf( "%c", argv[ argidx ][ charIdx ] );
                    break;
            }
        }
        if( argidx < argc - 1 )
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