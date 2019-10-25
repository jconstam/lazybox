#include <string>
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

        static void checkVector( vector<string> expected, string input, char delimiter )
        {
            vector<string> actual = StringCommon::split( input, delimiter );

            EXPECT_EQ( expected.size( ), actual.size( ) ) << "\"" << input << "\"";
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

TEST_F( StringCommonTest, Split )
{
    checkVector( { }, "", ' ' );
    checkVector( { "one" }, "one", ' ' );
    checkVector( { "one" }, " one ", ' ' );
    checkVector( { "one", "two", "three" }, "one two three", ' ' );
    checkVector( { "one", "two", "three" }, "     one     two     three     ", ' ' );
    checkVector( { }, "", ' ' );
    checkVector( { "one" }, "one", 'x' );
    checkVector( { "one" }, " one ", 'x' );
    checkVector( { "one", "two", "three" }, "onextwoxthree", 'x' );
    checkVector( { "one", "two", "three" }, "     one  x  two  x  three     ", 'x' );
}