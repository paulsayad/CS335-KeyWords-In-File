#include "KeywordsInFile.cpp"
#include <iostream>

int main()
{   
    std::string keywords = "Keywords.txt";
    std::string text = "Text.txt";
    KeywordsInFile travis(keywords, text);
    std::cout << "Keyword : Total Occurrences" << std::endl;
    std::cout << travis;

    std::cout << std::endl;

    std::cout << "Number of times 'Travis' is found in line 2 (Expected Result: 2) " << std::endl;
    std::cout << "The word 'Travis' appears " << travis.KeywordInLine("Travis", 2) << " time(s) in line 2" << std::endl;

    return 0;
}