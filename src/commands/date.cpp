/*
    LAZYBOX_COMMAND
    @name date
    @descrip Gets date/time information
    @function run_date
 */

#include <iostream>
#include <ctime>

#include "parseArgs.h"

using namespace std;

#define PARAM_COUNT     ( 1U )

typedef struct
{
    const char* desiredDate;
} DATE_PARAMS;

static const ARG_DATA argInfo[ PARAM_COUNT ] =
{
    { 'd', false, ARG_DATA_TYPE_STRING, offsetof( DATE_PARAMS, desiredDate ) }
};

int run_date( int argc, char* argv[ ] )
{
    int startIndex;
    DATE_PARAMS params = { "now" };

    if( !parseArgs( argInfo, PARAM_COUNT, &( params ), &( startIndex ), argc, argv ) )
    {
        return 1;
    }

    const char* format = "%a %b %d %T %Z %Y";
    if( startIndex < argc )
    {
        format = argv[ startIndex ];
    }

    if( format[ 0 ] != '+' )
    {
        cout << "date: invalid date \'" << format << "\'" << endl;
        return 1;
    }
    else
    {
        time_t currTime = time( 0 );
        struct tm* timeData = localtime( &( currTime ) );
        char buffer[ 100 ] = { 0 };

        strftime( buffer, 100, &( format[ 1 ] ), timeData );

        cout << buffer << endl;

        return 0;
    }
}