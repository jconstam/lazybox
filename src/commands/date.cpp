/*
    LAZYBOX_COMMAND
    @name date
    @descrip Gets date/time information
    @function run_date

    @config CMD_DATE

    @test noparams
    @test dateFormat01 "+%%"
    @test dateFormat02 "+%a   %-a   %_a   %0a   %^a   %#a"
    @test dateFormat03 "+%A   %-A   %_A   %0A   %^A   %#A"
    @test dateFormat04 "+%b   %-b   %_b   %0b   %^b   %#b"
    @test dateFormat05 "+%B   %-B   %_B   %0B   %^B   %#B"
    dateFormat06 "+%c   %-c   %_c   %0c   %^c   %#c"
    @test dateFormat07 "+%C   %-C   %_C   %0C   %^C   %#C"
    @test dateFormat08 "+%d   %-d   %_d   %0d   %^d   %#d"
    @test dateFormat09 "+%D   %-D   %_D   %0D   %^D   %#D"
    @test dateFormat10 "+%e   %-e   %_e   %0e   %^e   %#e"
    @test dateFormat11 "+%F   %-F   %_F   %0F   %^F   %#F"
    @test dateFormat12 "+%g   %-g   %_g   %0g   %^g   %#g"
    @test dateFormat13 "+%G   %-G   %_G   %0G   %^G   %#G"
    @test dateFormat14 "+%h   %-h   %_h   %0h   %^h   %#h"
    @test dateFormat15 "+%H   %-H   %_H   %0H   %^H   %#H"
    @test dateFormat16 "+%I   %-I   %_I   %0I   %^I   %#I"
    @test dateFormat17 "+%j   %-j   %_j   %0j   %^j   %#j"
    @test dateFormat18 "+%k   %-k   %_k   %0k   %^k   %#k"
    @test dateFormat19 "+%l   %-l   %_l   %0l   %^l   %#l"
    @test dateFormat20 "+%m   %-m   %_m   %0m   %^m   %#m"
    @test dateFormat21 "+%M   %-M   %_M   %0M   %^M   %#M"
    @test dateFormat22 "+%n   %-n   %_n   %0n   %^n   %#n"
    dateFormat23 "+%N   %-N   %_N   %0N   %^N   %#N"
    @test dateFormat24 "+%p   %-p   %_p   %0p   %^p   %#p"
    @test dateFormat25 "+%P   %-P   %_P   %0P   %^P   %#P"
    dateFormat26 "+%q   %-q   %_q   %0q   %^q   %#q"
    @test dateFormat27 "+%r   %-r   %_r   %0r   %^r   %#r"
    @test dateFormat28 "+%R   %-R   %_R   %0R   %^R   %#R"
    dateFormat29 "+%s   %-s   %_s   %0s   %^s   %#s"
    @test dateFormat30 "+%S   %-S   %_S   %0S   %^S   %#S"
    @test dateFormat31 "+%t   %-t   %_t   %0t   %^t   %#t"
    @test dateFormat32 "+%T   %-T   %_T   %0T   %^T   %#T"
    @test dateFormat33 "+%u   %-u   %_u   %0u   %^u   %#u"
    @test dateFormat34 "+%U   %-U   %_U   %0U   %^U   %#U"
    @test dateFormat35 "+%V   %-V   %_V   %0V   %^V   %#V"
    @test dateFormat36 "+%w   %-w   %_w   %0w   %^w   %#w"
    @test dateFormat37 "+%W   %-W   %_W   %0W   %^W   %#W"
    @test dateFormat38 "+%x   %-x   %_x   %0x   %^x   %#x"
    dateFormat39 "+%X   %-X   %_X   %0X   %^X   %#X"
    @test dateFormat40 "+%y   %-y   %_y   %0y   %^y   %#y"
    @test dateFormat41 "+%Y   %-Y   %_Y   %0Y   %^Y   %#Y"
    dateFormat42 "+%z   %:z   %::z  %:::z %Z"
 */

#include <iostream>
#include <ctime>
#include <locale.h>

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

    const char* format = "+%a %b %e %T %Z %Y";
    if( startIndex < argc )
    {
        format = argv[ startIndex ];
    }

    if( format[ 0 ] != '+' )
    {
        cerr << "date: invalid date \'" << format << "\'" << endl;
        return 1;
    }
    else
    {
        setlocale( LC_ALL, "" );

        time_t currTime = time( 0 );
        struct tm* timeData = localtime( &( currTime ) );
        char buffer[ 100 ] = { 0 };

        strftime( buffer, 100, &( format[ 1 ] ), timeData );

        cout << buffer << endl;

        return 0;
    }
}