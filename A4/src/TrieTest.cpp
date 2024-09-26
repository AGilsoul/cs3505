/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 4 - A Trie and Rule-of-Three
Description: This is the testing file for the Trie class
*/

#include "Trie.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::getline;


/// @brief Prints a vector to console output
/// @param vec Vector to print
void printVec(vector<string> vec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}


/// @brief Queries words in a vector to see if two tries give the same results
/// @param trie1 First trie to compare
/// @param trie2 Second trie to compare
/// @param queryWords Words to look for
/// @return Boolean, true if tries are identical, else false
bool triesAreEqual(Trie& trie1, Trie& trie2, vector<string> queryWords) {
    for (auto word : queryWords) {
        if (trie1.isWord(word) != trie2.isWord(word)) {
            return false;
        }
    }
    return true;
}


/// @brief Reads text from a file line by line
/// @param fileName String, file to read from
/// @return Vector containing each line of the file, empty if file does not exist
vector<string> readFile(string fileName) {
    string line;
    vector<string> lines;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }
    else {
        cout << "File \"" << fileName << "\" does not exist or is empty!" << endl;
    }
    return lines;
}


/// @brief Tests the Trie object agains words and queris from text files
/// @param wordFileName Name of text file containing words to add to Trie
/// @param queryFileName Name of text file containing words to query
/// @return Boolean, true if no issues, false if unable to read files or they are empty
bool fileQueryTest(string wordFileName, string queryFileName) {
    // get vectors containing words to add to a Trie, and words to query for
    vector<string> wordsToAdd = readFile(wordFileName);
    vector<string> wordsToCheck = readFile(queryFileName);

    // check if either file was empty/did not exist
    if (wordsToAdd.size() * wordsToCheck.size() == 0) {
        return false;
    }

    // create trie and add words
    Trie fileTrie;
    for (auto word : wordsToAdd) {
        fileTrie.addWord(word);
    }

    // check all words to query for
    for (auto word : wordsToCheck) {
        cout << "Checking " << word << ":" << endl;
        if (fileTrie.isWord(word)) {
            cout << "Word found" << endl;
        }
        else {
            cout << "Word not found" << endl;
        }
        vector<string> prefixVec = fileTrie.allWordsStartingWithPrefix(word);
        printVec(prefixVec);
    }

    return true;
}


/// @brief Tests the rule of three implementation for the Trie object
/// @return Boolean, true if all tests are passed
bool ruleOfThreeTest() {
    // list of words to query in tests
    vector<string> queryList = {"word", "wordone", "wordones", "wordtwo", "randomword"};
    // original trie to use for copying and assignment
    Trie originalTrie;
    originalTrie.addWord("wordone");
    originalTrie.addWord("wordones");
    originalTrie.addWord("wordtwo");

    // Trie made using copy constructor
    Trie copyConstructorTrie(originalTrie);
    // Original trie and copy constructor trie should be identical at this point
    if (triesAreEqual(originalTrie, copyConstructorTrie, queryList)) {
        cout << "Copy constructor equivalence test passed: Tries are identical after initial copy constructor" << endl;
    }
    else {
        cout << "Copy constructor equivalence test failed: Tries are not identical after initial copy constructor" << endl;
        return false;
    }

    // After adding word to copy constructor trie, they should no longer be identical, they should be independent
    copyConstructorTrie.addWord("word");
    if (!triesAreEqual(originalTrie, copyConstructorTrie, queryList)) {
        cout << "Copy constructor independence test passed: Tries are not identical after adding word to one" << endl;
    }
    else {
        cout << "Copy constructor independence test failed: Tries are identical after adding word to one" << endl;
        return false;
    }

    // Empty trie
    Trie assignmentTrie;
    // Copy contents of original through assignment
    assignmentTrie = originalTrie;
    // Original trie and assignment trie should be identical at this point
    if (triesAreEqual(originalTrie, assignmentTrie, queryList)) {
        cout << "Assignment equivalence test passed: Tries are identical after initial assignment" << endl;
    }
    else {
        cout << "Assignment equivalence test failed: Tries are not identical after initial assignment" << endl;
        return false;
    }

    // After adding word to assignment trie, they should no longer be identical, they should be independent
    assignmentTrie.addWord("randomword");
    if (!triesAreEqual(originalTrie, assignmentTrie, queryList)) {
        cout << "Assignment independence test passed: Tries are not identical after adding word to one" << endl;
    }
    else {
        cout << "Assignment independence test failed: Tries are identical after adding word to one" << endl;
        return false;
    }

    return true;
}



int main (int argc, char **argv)
{
    // Make sure we have the right number of arguments
    if (argc != 3) {
        cout << "Please provide two file names!" << endl;
        return 0;
    }
    // convert command line input to a string
    string wordFileName(argv[1]);
    string queryFileName(argv[2]);

    // run file input query test
    cout << endl << "FILE INPUT QUERY TEST" << endl;
    cout << "_____________________________________" << endl;
    if(fileQueryTest(wordFileName, queryFileName)) {
        cout << "FILE INPUT QUERY TEST SUCCESSFUL" << endl;
    }
    else {
        cout << "FILE INPUT QUERY TEST FAILED" << endl;
    }

    // run rule of three test
    cout << endl << "RULE OF THREE TEST" << endl;
    cout << "_____________________________________" << endl;
    if (ruleOfThreeTest()) {
        cout << "RULE OF THREE TEST SUCCESSFUL" << endl;
    }
    else {
        cout << "RULE OF THREE TEST FAILED" << endl;
    }
    cout << endl;

    return 0;
}


