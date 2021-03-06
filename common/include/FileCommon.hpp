#ifndef FILE_COMMON_HPP__
#define FILE_COMMON_HPP__

#include <string>

class FileCommon
{
    public:
        static std::string readEntireFile( std::string filePath );
        static bool fileExists( std::string filePath );
        static std::string trimString( std::string raw );
        static std::string removeWhitespace( std::string raw );
};

#endif