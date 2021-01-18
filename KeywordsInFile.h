#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

class KeywordsInFile
{   
    private:
        long int _numOfLines;
        std::unordered_map<std::string, long int> _keywords;
        std::unordered_map<std::string, long int> _text;
    public:
        KeywordsInFile(std::string filename_with_keywords, std::string filename_with_text);
        KeywordsInFile() = delete; 
        bool KeywordFound(const std::string& keyword) const;
        long int KeywordInLine(const std::string& keyword,  const int& line_number) const;
        long int TotalOccurrences(const std::string& keyword) const;
        friend std::ostream& operator<<(std::ostream& out, const KeywordsInFile& trg);   
};