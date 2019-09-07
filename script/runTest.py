#!/usr/bin/python3

import os
import sys
import argparse
import subprocess

def parseArgs( ):
    parser = argparse.ArgumentParser( description='' )
    parser.add_argument( '-c', '--command', required=True, help='Name of the command to execute.' )
    parser.add_argument( '-b', '--buildPath', required=True, help='Path to where the Lazybox binaries and symlink were built.' )
    parser.add_argument( '-w', '--workingPath', required=False, default=os.getcwd( ), help='Option working directory for the test.' )
    parser.add_argument( '-s', '--useSymlink', required=False, action='store_true', help='Whether to use the symlink or call the lazybox binary directly.')
    parser.add_argument( '-p', '--parameters', required=False, nargs=argparse.REMAINDER, default=[], help='Parameters to pass to command.' )

    return parser.parse_args( )

def executeCommand( filePath, command ):
    print( 'Running command {}'.format( ' '.join( command ) ) )
    with open( filePath, 'w' ) as outputFile:
        output = subprocess.Popen( command, stdout=outputFile )
        output.wait( )

if __name__ == "__main__":
    args = parseArgs( )
    
    systemCommand = [ args.command ]
    systemCommand.extend( args.parameters )
    systemOutputFilePath = os.path.abspath( os.path.join( args.workingPath, 'system_{}_output'.format( args.command ) ) )

    if args.useSymlink:
        lazyBoxCommand = [ os.path.join( args.buildPath, args.command ) ]
    else:
        lazyBoxCommand = [ os.path.join( args.buildPath, 'lazybox' ), args.command ]
    lazyBoxCommand.extend( args.parameters )
    lazyBoxOutputFilePath = os.path.abspath( os.path.join( args.workingPath, 'lazybox_{}_output'.format( args.command ) ) )

    diffCommand = [ 'diff', systemOutputFilePath, lazyBoxOutputFilePath ]

    executeCommand( systemOutputFilePath, systemCommand )
    executeCommand( lazyBoxOutputFilePath, lazyBoxCommand )

    diffOutput = subprocess.Popen( diffCommand, stdout=subprocess.PIPE, stderr=subprocess.STDOUT )
    diffOutput.wait( )
    result = diffOutput.returncode
    stdout,stderr = diffOutput.communicate( )

    os.remove( systemOutputFilePath )
    os.remove( lazyBoxOutputFilePath )

    if result == 0:
        print( 'GOOD' )
    else:
        print( 'BAD' )
        print( stdout.decode( 'utf-8' ) )

    sys.exit( result )
