/*
    LAZYBOX_COMMAND
    @name date
    @descrip Gets date/time information
    @function run_date
 */

#include <iostream>
#include <ctime>

using namespace std;

int run_date( int argc, char* argv[ ] )
{
    time_t currTime = time( 0 );
    struct tm* timeData = localtime( &( currTime ) );
    char buffer[ 100 ] = { 0 };

    strftime( buffer, 100, "%A %B %d %Y, %H:%M:%S (UTC%z)", timeData );

    cout << buffer << endl;

    return 0;
}