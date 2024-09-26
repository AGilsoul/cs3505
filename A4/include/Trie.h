/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 4 - A Trie and Rule-of-Three
Description: This is the header file for the Trie class
*/
#ifndef TRIE_H
#define TRIE_H


#include <vector>
#include <string>

using std::string;
using std::vector;

// constant to denote alphabet size
const int N = 26;
// constant representing the beginning character of the alphabet
const char minChar = 'a';

class Trie {
    // C-style pointer array containing child nodes
    Trie* children[N] { nullptr };
    // Flag denoting if this Trie node ends a word (true) or not (false)
    bool wordFlag = false;

public:
    /// @brief Default constructor for Trie
    Trie();

    /// @brief Copy constructor for Trie
    /// @param other Trie to copy
    Trie(const Trie& other);

    /// @brief Assignment operator for Trie
    /// @param other Copied Trie to swap with
    /// @return Trie with swapped data
    Trie& operator=(Trie other);

    /// @brief Recursive desctructor for Trie
    ~Trie();

    /// @brief Add a word to the Trie
    /// @param word Word to add
    void addWord(string word);

    /// @brief Check if a word exists in the Trie
    /// @param word Word to look for
    /// @return Boolean true if word in Trie, else false
    bool isWord(string word);

    /// @brief Get all words starting with a given prefix in the Trie
    /// @param prefix Prefix to look for
    /// @return Vector containing all words in the Trie beginning with the given prefix
    vector<string> allWordsStartingWithPrefix(string prefix);

private:
    
    /// @brief Get alphabet index value of character
    /// @param character Character to get index value of
    /// @return Integer index of character in alphabet, -1 if not in alphabet
    int getCharacterIndex(char character);
};

#endif