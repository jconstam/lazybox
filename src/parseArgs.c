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
							*( ( bool* ) ( data + config[ configIndex ].offset ) ) = true;
							break;
						case( ARG_DATA_TYPE_INT ):
							memcpy( data + config[ configIndex].offset, optarg, sizeof( int ) );
							break;
						case( ARG_DATA_TYPE_STRING ):
							memcpy( data + config[ configIndex].offset, optarg, sizeof( char* ) );
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