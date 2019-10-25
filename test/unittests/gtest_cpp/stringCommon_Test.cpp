#include <vector>

#include "gtest/gtest.h"

#include "StringCommon.hpp"

using namespace std;

class StringCommonTest : public ::testing::Test
{
    protected:
        void SetUp( ) override
        {
            
        }

        void TearDown( ) override
        {

        }
};

TEST_F( StringCommonTest, Trim )
{
    EXPECT_STREQ( "testing", StringCommon::trim( "testing" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::trim( "    testing" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::trim( "testing    " ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::trim( "  testing  " ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::trim( "\ttesting" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::trim( "testing\t" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::trim( "\ttesting\t" ).c_str( ) );
}

TEST_F( StringCommonTest, RemoveWhitespace )
{
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "testing" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "    testing" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "testing    " ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "  testing  " ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "  t  e  s  t  i  n  g  " ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "\ttesting" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "testing\t" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "\ttesting\t" ).c_str( ) );
    EXPECT_STREQ( "testing", StringCommon::removeWhitespace( "\tt\te\ts\tt\ti\tn\tg\t" ).c_str( ) );
}