#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "cmdList.hpp"
#include "cmdRegistry.hpp"

using namespace std;

class MockCmdList : public CmdListBase
{
    public:
        MOCK_METHOD( CmdFunc, getFunction, ( std::string ) );
};

using ::testing::Mock;
using ::testing::Return;
using ::testing::_;

class RunCommandTest : public ::testing::Test
{
    protected:
        static bool customFunctionRan;
        static int customFunctionReturnValue;
        static int customFunctionARGC;
        static vector<string> customFunctionARGV;

        void SetUp( ) override
        {
            customFunctionRan = false;
            customFunctionReturnValue = 0;
            customFunctionARGC = 0;
            customFunctionARGV.clear( );
        }

        void TearDown( ) override
        {

        }

        static void RunCommand( MockCmdList& mockCmdList, vector<const char*> parameters, int expectedResult, string expectedOutput, int line )
        {
            testing::internal::CaptureStdout( );
            EXPECT_EQ( expectedResult, CommandRegistry::runCommand( mockCmdList, parameters.size( ), ( char** ) parameters.data( ) ) ) << "Actual error is on line " << line;
            EXPECT_EQ( expectedOutput, testing::internal::GetCapturedStdout( ) ) << "Actual error is on line " << line;
        }

        static int customFunction( int argc, char* argv[ ] )
        {
            customFunctionRan = true;
            customFunctionARGC = argc;
            for( int i = 0; i < argc; i++ )
            {
                customFunctionARGV.push_back( argv[ i ] );
            }

            return customFunctionReturnValue;
        }
};

bool RunCommandTest::customFunctionRan;
int RunCommandTest::customFunctionReturnValue;
int RunCommandTest::customFunctionARGC;
vector<string> RunCommandTest::customFunctionARGV;

TEST_F( RunCommandTest, Lazybox )
{
    MockCmdList mockCmdList;
    RunCommand( mockCmdList, { "lazybox" }, 0, "LazyBox - BusyBox's less portable, less functional cousin.\n", __LINE__ );

    EXPECT_EQ( false, customFunctionRan );
}
TEST_F( RunCommandTest, CommandNotFound )
{
    MockCmdList mockCmdList;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( nullptr ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "lazybox", "command" }, 1, "Could not find command \"command\"\n", __LINE__ );

    EXPECT_EQ( false, customFunctionRan );
}
TEST_F( RunCommandTest, CustomCommand )
{
    MockCmdList mockCmdList;

    customFunctionReturnValue = 3;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( customFunction ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "lazybox", "command" }, 3, "", __LINE__ );

    EXPECT_EQ( true, customFunctionRan );
    EXPECT_EQ( 1, customFunctionARGC );
    EXPECT_STREQ( "command", customFunctionARGV[ 0 ].c_str( ) );
}
TEST_F( RunCommandTest, CustomCommandWithPath )
{
    MockCmdList mockCmdList;

    customFunctionReturnValue = 3;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( customFunction ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "/path/to/the/lazybox", "command" }, 3, "", __LINE__ );

    EXPECT_EQ( true, customFunctionRan );
    EXPECT_EQ( 1, customFunctionARGC );
    EXPECT_STREQ( "command", customFunctionARGV[ 0 ].c_str( ) );
}
TEST_F( RunCommandTest, CustomCommandManyArgs )
{
    MockCmdList mockCmdList;

    customFunctionReturnValue = 3;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( customFunction ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "lazybox", "command", "A", "B", "C", "D", "E" }, 3, "", __LINE__ );

    EXPECT_EQ( true, customFunctionRan );
    EXPECT_EQ( 6, customFunctionARGC );
    EXPECT_STREQ( "command", customFunctionARGV[ 0 ].c_str( ) );
    EXPECT_STREQ( "A", customFunctionARGV[ 1 ].c_str( ) );
    EXPECT_STREQ( "B", customFunctionARGV[ 2 ].c_str( ) );
    EXPECT_STREQ( "C", customFunctionARGV[ 3 ].c_str( ) );
    EXPECT_STREQ( "D", customFunctionARGV[ 4 ].c_str( ) );
    EXPECT_STREQ( "E", customFunctionARGV[ 5 ].c_str( ) );
}
TEST_F( RunCommandTest, SymlinkCommandNotFound )
{
    MockCmdList mockCmdList;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( nullptr ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "command" }, 1, "Could not find command \"command\"\n", __LINE__ );

    EXPECT_EQ( false, customFunctionRan );
}
TEST_F( RunCommandTest, SymlinkCustomCommand )
{
    MockCmdList mockCmdList;

    customFunctionReturnValue = 3;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( customFunction ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "command" }, 3, "", __LINE__ );

    EXPECT_EQ( true, customFunctionRan );
    EXPECT_EQ( 1, customFunctionARGC );
    EXPECT_STREQ( "command", customFunctionARGV[ 0 ].c_str( ) );
}
TEST_F( RunCommandTest, SymlinkCustomCommandWithPath )
{
    MockCmdList mockCmdList;

    customFunctionReturnValue = 3;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( customFunction ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "/path/to/the/command" }, 3, "", __LINE__ );

    EXPECT_EQ( true, customFunctionRan );
    EXPECT_EQ( 1, customFunctionARGC );
    EXPECT_STREQ( "/path/to/the/command", customFunctionARGV[ 0 ].c_str( ) );
}
TEST_F( RunCommandTest, SymlinkCustomCommandManyArgs )
{
    MockCmdList mockCmdList;

    customFunctionReturnValue = 3;

    ON_CALL( mockCmdList, getFunction( "command" ) ).WillByDefault( Return( customFunction ) );
    EXPECT_CALL( mockCmdList, getFunction( "command" ) ).Times( 1 );
    
    RunCommand( mockCmdList, { "command", "A", "B", "C", "D", "E" }, 3, "", __LINE__ );

    EXPECT_EQ( true, customFunctionRan );
    EXPECT_EQ( 6, customFunctionARGC );
    EXPECT_STREQ( "command", customFunctionARGV[ 0 ].c_str( ) );
    EXPECT_STREQ( "A", customFunctionARGV[ 1 ].c_str( ) );
    EXPECT_STREQ( "B", customFunctionARGV[ 2 ].c_str( ) );
    EXPECT_STREQ( "C", customFunctionARGV[ 3 ].c_str( ) );
    EXPECT_STREQ( "D", customFunctionARGV[ 4 ].c_str( ) );
    EXPECT_STREQ( "E", customFunctionARGV[ 5 ].c_str( ) );
}