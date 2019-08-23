#include "unity.h"

extern void DO_ALL_TESTS( void );

int main( void )
{
	UNITY_BEGIN( );
	if( TEST_PROTECT( ) )
	{
		DO_ALL_TESTS( );
	}

	return UNITY_END( );
}