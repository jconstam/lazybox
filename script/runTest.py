#!/bin/bash/python3

import sys
import subprocess

first = True
inCommand = True
splitter = "CMD_OUTPUT_SPLITTER"

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

out = subprocess.Popen( command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT )
stdout,stderr = out.communicate( )

actualOutput = stdout.decode( 'utf-8' )
expectedOutput = bytes( ' '.join( output ), 'utf-8' ).decode( 'unicode_escape' )

print( "ACTUAL:   \"" + actualOutput + "\"" )
print( "EXPECTED: \"" + expectedOutput + "\"" )

if actualOutput == expectedOutput:
	sys.exit( 0 )
else:
	sys.exit( 1 )
