#include <vector>

#include "gtest/gtest.h"

#include "FileCommon.hpp"

using namespace std;

class FileCommonTest : public ::testing::Test
{
    protected:
        void SetUp( ) override
        {
            
        }

        void TearDown( ) override
        {

        }
};

TEST_F( FileCommonTest, FileExists )
{
    EXPECT_FALSE( FileCommon::fileExists( "blahblah" ) );
    EXPECT_TRUE( FileCommon::fileExists( __FILE__ ) );
}

TEST_F( FileCommonTest, ReadEntireFile )
{
    EXPECT_STREQ( "", FileCommon::readEntireFile( "blahblah" ).c_str( ) );
    EXPECT_STRNE( "", FileCommon::readEntireFile( __FILE__ ).c_str( ) );
}