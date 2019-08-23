#ifndef PARSE_ARGS_H__
#define PARSE_ARGS_H__

#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>

typedef enum
{
	ARG_DATA_TYPE_BOOL,
	ARG_DATA_TYPE_INT,
	ARG_DATA_TYPE_STRING,

	ARG_DATA_TYPE_COUNT
} ARG_DATA_TYPE;

typedef struct
{
	char flag;
	bool hasString;
	ARG_DATA_TYPE type;
	int offset;
} ARG_DATA;

bool parseArgs( const ARG_DATA* config, const size_t configSize, void* data, int* index, int argc, char* argv[ ] );

#endif