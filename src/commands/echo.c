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

int run_echo( int argc, char* argv[ ] )
{
    for( int i = 0; i < argc; i++ )
    {
        printf( "%s", argv[ i ] );
        if( i < argc - 1 )
        {
            printf( " " );
        }
    }

    printf( "\n" );

    return 0;
}