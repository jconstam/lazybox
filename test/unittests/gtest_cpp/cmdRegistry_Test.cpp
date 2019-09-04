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

using ::testing::Return;
using ::testing::_;

class RunCommandTest : public ::testing::Test
{
    protected:
        void SetUp( ) override
        {

        }

        void TearDown( ) override
        {

        }

        static void RunCommand( vector<const char*> parameters, int expectedResult, string expectedOutput, int line )
        {
            MockCmdList cmdList;

            testing::internal::CaptureStdout( );
            EXPECT_EQ( expectedResult, CommandRegistry::runCommand( cmdList, parameters.size( ), ( char** ) parameters.data( ) ) ) << "Actual error is on line " << line;
            EXPECT_EQ( expectedOutput, testing::internal::GetCapturedStdout( ) ) << "Actual error is on line " << line;
        }
};

TEST_F( RunCommandTest, Dummy )
{
    RunCommand( { "lazybox" }, 0, "LazyBox - BusyBox's less portable, less functional cousin.\n", __LINE__ );
}