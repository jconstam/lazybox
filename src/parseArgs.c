#include <string.h>
#include <stdlib.h>
#include <getopt.h>

#include <stdio.h>

#include "parseArgs.h"

bool parseArgs( const ARG_DATA* config, const size_t configSize, void* data, int* index, int argc, char* argv[ ] )
{
	bool successful = true;
	char* optString;
	optString = calloc( 2U, configSize );

	uint32_t configIndex;
	uint32_t stringIndex = 0U;
	for( configIndex = 0U; configIndex < configSize; configIndex++ )
	{
		optString[ stringIndex ] = config[ configIndex ].flag;
		stringIndex++;
		if( config[ configIndex ].hasString )
		{
			optString[ stringIndex ] = ':';
			stringIndex++;
		}
	}

	opterr = 0;

    int opt = 0;
	while( opt != -1 )
    {
		opt = getopt( argc, argv, optString );
		if( opt == '?' )
		{
			successful = false;
			break;
		}
		else if( opt == -1 )
		{
			*index = optind;
			break;
		}
		else
		{
			for( configIndex = 0U; configIndex < configSize; configIndex++ )
			{
				if( opt == config[ configIndex ].flag )
				{
					switch( config[ configIndex ].type )
					{
						case( ARG_DATA_TYPE_BOOL ):
							{
								*( ( bool* ) ( ( uintptr_t ) data + ( uintptr_t ) config[ configIndex ].offset ) ) = true;
							}
							break;
						case( ARG_DATA_TYPE_INT ):
							{
								int value = atoi( optarg );
								memcpy( ( void* ) ( ( uintptr_t ) data + ( uintptr_t ) config[ configIndex ].offset ), &( value ), sizeof( int ) );
							}
							break;
						case( ARG_DATA_TYPE_STRING ):
							{
								char** string = ( char** )( ( uintptr_t ) ( ( char* ) data ) + ( uintptr_t ) config[ configIndex ].offset );
								*string = optarg;
							}
							break;
						default:
							break;
					}
					
					break;
				}
			}

			if( configIndex >= configSize )
			{
				successful = false;
				break;
			}
		}
    }

    free( optString );

    return successful;
}