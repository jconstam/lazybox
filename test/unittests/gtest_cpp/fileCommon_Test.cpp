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

TEST_F( FileCommonTest, TrimString )
{
    EXPECT_STREQ( "testing", FileCommon::trimString( "testing" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::trimString( "    testing" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::trimString( "testing    " ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::trimString( "  testing  " ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::trimString( "\ttesting" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::trimString( "testing\t" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::trimString( "\ttesting\t" ).c_str( ) );
}

TEST_F( FileCommonTest, RemoveWhitespace )
{
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "testing" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "    testing" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "testing    " ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "  testing  " ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "  t  e  s  t  i  n  g  " ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "\ttesting" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "testing\t" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "\ttesting\t" ).c_str( ) );
    EXPECT_STREQ( "testing", FileCommon::removeWhitespace( "\tt\te\ts\tt\ti\tn\tg\t" ).c_str( ) );
}