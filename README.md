# CS335-Keyword-Locator

## About the Project

* Create a program that can read in keywords from a file and search another file for the keywords
* Can also find the total occurrences of the keyword and even in specific lines

## Project Design

* Two text files
1. Keywords.txt file holds the keywords
2. Text.txt file holds the text which will be searched

* KeywordsInFile function where all processing wil take place. Time Complexity: O(N + M) time
* KeywordFound(keyword) function which returns true if the specified keyword was found in the text. Returns false otherwise. Time Complexity: O(1) time.
* KeywordInLIne(keyword, line_number) function which returns the number of times the specified keyword was seen in the specified line of the text. Time Complexity: O(log L) time, where L is the number of times the keyword was found in the text.
* TotalOccurrences(keyword) function which returns the total number of the occurrences of the given keyword in the text. Time Complexity: O(log L) time, where L is the number of times the keyword was found in the text.
* Overload operator<< so when you can print the object of the class.

## How to Compile the Program

1. Download the files and put them in a directory
2. Navigate to your directory in your terminal and run the command
> g++ main.cpp -o main
3. To execute the program run the command
> ./main
