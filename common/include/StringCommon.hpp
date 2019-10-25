#ifndef STRING_COMMON_HPP__
#define STRING_COMMON_HPP__

#include <string>
#include <vector>

class StringCommon
{
    public:
        static std::string trim( std::string raw );
        static std::string removeWhitespace( std::string raw );
        static std::vector<std::string> split( const std::string& input, const char delimiter );
};

#endif