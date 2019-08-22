#include "unity.h"

void test_check( void )
{
	TEST_ASSERT( 0 == 0 );
}

void setUp( void )
{

}

void tearDown( void )
{

}

int main( void )
{
	UNITY_BEGIN( );

	RUN_TEST( test_check );

	return UNITY_END( );
}