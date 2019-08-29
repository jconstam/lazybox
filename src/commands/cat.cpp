/*
    LAZYBOX_COMMAND
    @name cat
    @descrip Concatenate file(s) and print them to standard out.
    @function run_cat
 */

#include <iostream>

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

int run_cat( int argc, char* argv[ ] )
{
    int startIndex;
    CAT_PARAMS params = { false };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    return 0;
}