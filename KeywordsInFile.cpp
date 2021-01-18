#include "KeywordsInFile.h"

/**
 *  Constructor
 *  @param filename_with_keywords the filename for the keywords file
 *  @param filename_with_text the filename for the text file
 */
KeywordsInFile::KeywordsInFile(std::string filename_with_keywords, std::string filename_with_text)
{      
    // Sets variables
    std::ifstream keyFile, textFile;
    std::string line, words;
    std::unordered_map<std::string, long int>::const_iterator got;
    long int x = 0, lineNumber = 1;
    bool writing = false;

    /* Opens files & exits if unable to open file */

    // Opens keyword file
    keyFile.open(filename_with_keywords);
    if (!keyFile) {
        std::cout << "Unable to open file";
        exit(1); // Terminate with error
    }

    // Opens text file
    textFile.open(filename_with_text);
    if (!textFile) {
        std::cout << "Unable to open file";
        exit(1); // Terminate with error
    }

    // Puts keywords into an unordered map called _keywords // key = word && value = occurrences
    while (std::getline(keyFile, line)){
        for(char scanner : line)
        {
            if(!isalpha(scanner))
            {   
                if(writing)
                {
                    _keywords[words] = 0;
                    writing = false;
                }
                words = "";
            } else {
                words += scanner;  
                writing = true;
            }
        }
    }

    // Checks if there is a last word that didn't get inputted in _keywords
    if(words != "")
    {
        _keywords[words] = 0;
    }
    
    // Resets variables
    writing = false;
    words = "";

    // Puts text into an unordered map called _text // key = word && value = int of how many per line
    // Ex. 123, 3 occurences in line 1, 2 occurences in line 2, 1 occurence in line 1
    // Checks for keywords and adds 1 to value of the keyword
    while (std::getline(textFile, line)){
        for(char scanner : line)
        {
            if(!isalpha(scanner))
            {   
                if(writing)
                {   
                    // Checks if the word is a keyword, if it is, plus one to keywords occurrence
                    got = _keywords.find(words);
                    if (got != _keywords.end())
                    {
                        x = got->second;
                        _keywords.erase(words);
                        x++;
                        _keywords.insert({words, x});
                    }

                    if(_text.count(words) > 0)
                    {   
                        x = _text.find(words)->second;
                        x += lineNumber;
                        _text[words] = x;
                    } else {
                        _text[words] = lineNumber;
                    }
                    writing = false;
                }
                words = "";
            } else {
                words += scanner;  
                writing = true;
            }
        }
        lineNumber *= 10;
        _numOfLines++;
    }

    // Checks if there is a last word that didn't get inputted in _keywords
    if(words != "")
    {   
        lineNumber /= 10;
        // Checks if the word is a keyword, if it is, plus one to keywords occurrence
        got = _keywords.find(words);
        if (got != _keywords.end())
        {
            x = got->second;
            _keywords.erase(words);
            x++;
            _keywords.insert({words, x});
        }
        if(_text.count(words) > 0)
        {   
            x = _text.find(words)->second;
            x += lineNumber;
            _text[words] = x;
        } else {
            _text[words] = lineNumber;
        }
    }   

    /* Closes the files */
    keyFile.close();
    textFile.close();
}

/**
 *   KeywordFound
 *   @param keyword the keyword being searched for
 *   @return true if the specified keyword was found in the text, returns false otherwise
 */
bool KeywordsInFile::KeywordFound(const std::string& keyword) const
{   
    // Iterator to find the keyword
    std::unordered_map<std::string, long int>::const_iterator got = _keywords.find(keyword);
    
    // Keyword is non-existant
    if(got == _keywords.end())
        return false;

    // Return true if keyword appears at least once, return false if 0
    if(got->second > 0)
        return true;
    else
        return false;
}

/**
 *  KeywordInLine
 *  @param keyword the keyword being searched for
 *  @param line_number the line number where the keyword should/should not be
 *  @return the number of times the keyword was in the specified line
 */ 
long int KeywordsInFile::KeywordInLine(const std::string& keyword,  const int& line_number) const
{   
    if(!KeywordFound(keyword) || _numOfLines < line_number)
        return 0;

    std::string number = std::to_string(_text.find(keyword)->second);
    char result = number[number.size() - line_number];

    return result - '0';
}

/**
 *  TotalOccurrences
 *  @param keyword the keyword whose total occurrences we want
 *  @return the number of times the keyword appears in the text
 */
long int KeywordsInFile::TotalOccurrences(const std::string& keyword) const
{   
    if(!KeywordFound(keyword))
        return 0;

    // Iterator to find the keyword
    std::unordered_map<std::string, long int>::const_iterator got = _keywords.find(keyword);

    // Returns the keywords total occurrences
    if(got->second > 0)
        return got->second;
    else
        return 0;
}

/**
 *  operator<<
 *  @param out the output stream
 *  @param trg the target object to be outputted
 *  @return the output stream when done
 */
std::ostream& operator<<(std::ostream& out, const KeywordsInFile& trg)
{   
    // For loop scans keywords & prints out key and value
    for(auto& x: trg._keywords)
        out << x.first << " : " << x.second << std::endl;

    // Returns the output stream
    return out;
}