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

def getStdoutFileName( filePath ):
    return '{}_stdout'.format( filePath )
def getStderrFileName( filePath ):
    return '{}_stderr'.format( filePath )

def executeCommand( filePath, command ):
    print( 'Running command {}'.format( ' '.join( command ) ) )
    with open( getStdoutFileName( filePath ), 'w' ) as stdoutFile:
        with open( getStderrFileName( filePath ), 'w' ) as stderrFile:
            output = subprocess.Popen( command, stdout=stdoutFile, stderr=stderrFile )
            output.wait( )

def compareCommands( file1, file2 ):
    command = [ 'diff', file1, file2 ]

    output = subprocess.Popen( command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT )
    output.wait( )

    return output.returncode, output.communicate( )[ 0 ].decode( 'utf-8' )

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

    executeCommand( systemOutputFilePath, systemCommand )
    executeCommand( lazyBoxOutputFilePath, lazyBoxCommand )

    stdoutReturn, stdoutOutput = compareCommands( getStdoutFileName( systemOutputFilePath ), getStdoutFileName( lazyBoxOutputFilePath ) )
    stderrReturn, stderrOutput = compareCommands( getStderrFileName( systemOutputFilePath ), getStderrFileName( lazyBoxOutputFilePath ) )

    os.remove( getStdoutFileName( systemOutputFilePath ) )
    os.remove( getStdoutFileName( lazyBoxOutputFilePath ) )
    os.remove( getStderrFileName( systemOutputFilePath ) )
    os.remove( getStderrFileName( lazyBoxOutputFilePath ) )

    if stdoutReturn == 0 and stderrReturn == 0:
        print( 'GOOD' )
    else:
        print( 'BAD' )
        print( 'STDOUT: ', stdoutReturn )
        print( stdoutOutput )
        print( 'STDERR: ', stderrReturn )
        print( stderrOutput )

    sys.exit( stdoutReturn + stderrReturn )
