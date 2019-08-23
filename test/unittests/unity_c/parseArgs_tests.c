#include <getopt.h>

#include "unity.h"
#include "parseArgs.h"

#define NUM_PARAMS_ONE 		( 3U )

#define TEST_COMMAND		"./path/to/command"
#define INIT_STRING			"foo"
#define FINAL_STRING		"bar"

typedef struct
{
	bool flag;
	int value;
	char* string;
} PARAMS_ONE;

static PARAMS_ONE parameters1;

static const ARG_DATA param1Config[ NUM_PARAMS_ONE ] =
{
	{ 'f', false, ARG_DATA_TYPE_BOOL, offsetof( PARAMS_ONE, flag ) },
	{ 'v', true, ARG_DATA_TYPE_INT, offsetof( PARAMS_ONE, value ) },
	{ 's', true, ARG_DATA_TYPE_STRING, offsetof( PARAMS_ONE, string ) }
};

void setUp( void )
{
	optind = 0;

	parameters1.flag = false;
	parameters1.value = 10;
	parameters1.string = INIT_STRING;

	printf( "BEFORE\n" );
	printf( "FLAG:   %s\n", ( parameters1.flag ? "TRUE" : "FALSE" ) );
	printf( "VALUE:  %d\n", parameters1.value );
	printf( "STRING: %s\n", parameters1.string );
}

void tearDown( void )
{
	printf( "AFTER\n" );
	printf( "FLAG:   %s\n", ( parameters1.flag ? "TRUE" : "FALSE" ) );
	printf( "VALUE:  %d\n", parameters1.value );
	printf( "STRING: %s\n", parameters1.string );
}

static void test_NoArgs( void )
{
	int index = -1;
	int argc = 1;
	char* argv[ 1 ] = { TEST_COMMAND };

	bool result = parseArgs( param1Config, NUM_PARAMS_ONE, &( parameters1 ), &( index ), argc, argv );
	TEST_ASSERT_TRUE( result );
	TEST_ASSERT_EQUAL_INT( 1, index );

	TEST_ASSERT_FALSE( parameters1.flag );
	TEST_ASSERT_EQUAL_INT( 10, parameters1.value );
	TEST_ASSERT_EQUAL_STRING( INIT_STRING, parameters1.string );
}

static void test_OnlyFlag( void )
{
	int index = -1;
	int argc = 2;
	char* argv[ 2 ] = { TEST_COMMAND, "-f" };

	TEST_ASSERT_TRUE( parseArgs( param1Config, NUM_PARAMS_ONE, &( parameters1 ), &( index ), argc, argv ) );
	TEST_ASSERT_EQUAL_INT( 2, index );

	TEST_ASSERT_TRUE( parameters1.flag );
	TEST_ASSERT_EQUAL_INT( 10, parameters1.value );
	TEST_ASSERT_EQUAL_STRING( INIT_STRING, parameters1.string );
}

static void test_OnlyValue( void )
{
	int index = -1;
	int argc = 3;
	char* argv[ 3 ] = { TEST_COMMAND, "-v", "200" };

	TEST_ASSERT_TRUE( parseArgs( param1Config, NUM_PARAMS_ONE, &( parameters1 ), &( index ), argc, argv ) );
	TEST_ASSERT_EQUAL_INT( 3, index );

	TEST_ASSERT_FALSE( parameters1.flag );
	TEST_ASSERT_EQUAL_INT( 200, parameters1.value );
	TEST_ASSERT_EQUAL_STRING( INIT_STRING, parameters1.string );
}

static void test_OnlyString( void )
{
	int index = -1;
	int argc = 3;
	char* argv[ 3 ] = { TEST_COMMAND, "-s", FINAL_STRING };

	TEST_ASSERT_TRUE( parseArgs( param1Config, NUM_PARAMS_ONE, &( parameters1 ), &( index ), argc, argv ) );
	TEST_ASSERT_EQUAL_INT( 3, index );

	TEST_ASSERT_FALSE( parameters1.flag );
	TEST_ASSERT_EQUAL_INT( 10, parameters1.value );
	TEST_ASSERT_EQUAL_STRING( FINAL_STRING, parameters1.string );
}


static void test_All( void )
{
	int index = -1;
	int argc = 6;
	char* argv[ 6 ] = { TEST_COMMAND, "-f", "-v", "200", "-s", FINAL_STRING };

	TEST_ASSERT_TRUE( parseArgs( param1Config, NUM_PARAMS_ONE, &( parameters1 ), &( index ), argc, argv ) );
	TEST_ASSERT_EQUAL_INT( 6, index );

	TEST_ASSERT_TRUE( parameters1.flag );
	TEST_ASSERT_EQUAL_INT( 200, parameters1.value );
	TEST_ASSERT_EQUAL_STRING( FINAL_STRING, parameters1.string );
}

void DO_ALL_TESTS( void )
{
	RUN_TEST( test_NoArgs );
	RUN_TEST( test_OnlyFlag );
	RUN_TEST( test_OnlyValue );
	RUN_TEST( test_OnlyString );
	RUN_TEST( test_All );
}
