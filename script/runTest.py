#!/usr/bin/python3

import sys
import subprocess

first = True
inCommand = True
splitter = 'CMD_OUTPUT_SPLITTER'

command = [ ]
output = [ ]

for arg in sys.argv:
	if first:
		first = False
	elif splitter in arg:
		inCommand = False
	elif inCommand:
		command.append( arg )
	else:
		output.append( arg )

if command[ 0 ][ 0 ] == '"':
	command[ 0 ] = command[ 0 ][ 1: ]
if command[ -1 ][ -1 ] == '"':
	command[ -1 ] = command[ -1 ][ : -1 ]
print( repr( 'COMMAND: "' + ' '.join( command ) + '"' ) )

out = subprocess.Popen( command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT )
stdout,stderr = out.communicate( )

actualOutput = repr( stdout.decode( 'utf-8' ) )
expectedOutput = repr( ' '.join( output ) )

print( 'ACTUAL:   "' + actualOutput + '"' )
print( 'EXPECTED: "' + expectedOutput + '"' )

if actualOutput == expectedOutput:
	print( 'GOOD' )
	sys.exit( 0 )
else:
	print( 'BAD' )
	sys.exit( 1 )
