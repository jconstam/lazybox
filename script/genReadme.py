#!/usr/bin/python

import json
import argparse

def parseArgs( ):
    parser = argparse.ArgumentParser( description='' )
    parser.add_argument( '-r', '--readmeDataFile', required=True, help='Absolute path of the README data file.' )
    parser.add_argument( '-m', '--moduleDataFile', required=True, help='Absolute path of the module data file.' )
    parser.add_argument( '-o', '--outputReadmeFile', required=True, help='Absolute path of the output README file.' )

    return parser.parse_args( )

def readJSONFile( fileName ):
    with open( fileName ) as json_file:
        return json.load( json_file )

if __name__ == "__main__":
    args = parseArgs( )

    readmeData = readJSONFile( args.readmeDataFile )
    moduleData = readJSONFile( args.moduleDataFile )

    with open( args.outputReadmeFile, 'w' ) as output_file:
        output_file.write( '# {}\n'.format( readmeData[ 'title' ] ) )
        for section in readmeData[ 'sections' ]:
            if section[ 'title' ]:
                output_file.write( '## {}\n'.format( section[ 'title' ] ) )
            output_file.write( '\n'.join( section[ 'text' ] ) )
            output_file.write( '\n\n' )
        output_file.write( '# Modules\n' )
        output_file.write( '|Command|Description|Difficulty|Status|\n' )
        output_file.write( '|-------|-----------|----------|------|\n' )
        for module in moduleData:
            output_file.write( '|{}|{}|{}|{}|\n'.format( module[ 'name' ], module[ 'description' ], module[ 'difficulty' ], module[ 'status' ] ) )