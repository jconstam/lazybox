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

        static int RunCommand( vector<const char*> parameters )
        {
            MockCmdList cmdList;
            return CommandRegistry::runCommand( cmdList, parameters.size( ), ( char** ) parameters.data( ) );
        }
};

TEST_F( RunCommandTest, Dummy )
{
    RunCommand( { "dummy" } );
}