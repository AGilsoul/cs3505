/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 4 - A Trie and Rule-of-Three
Description: This is the implementation file for the Trie class
*/

#include "Trie.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::swap;

Trie::Trie() {}


Trie::Trie(const Trie& other) {
    wordFlag = other.wordFlag;
    for (unsigned int i = 0; i < N; i++) {
        if (other.children[i] != nullptr) {
            children[i] = new Trie(*(other.children[i]));
        }
        else {
            children[i] = nullptr;
        }
    }
}

Trie& Trie::operator=(Trie other) {
    std::swap(wordFlag, other.wordFlag);
    for (unsigned int i = 0; i < N; i++) {
        swap(children[i], other.children[i]);
    }
    return *this;
}

Trie::~Trie() {
    for (unsigned int i = 0; i < N; i++) {
        delete children[i];
    }
}


void Trie::addWord(string word) {
    // if we are at the last node
    if (word.length() == 0) {
        wordFlag = true;
        return;
    }
    // check if we need to make a new Trie node
    int charVal = getCharacterIndex(word[0]);
    if (children[charVal] == nullptr) {
        children[charVal] = new Trie;
    }
    // recursive call with first (current) character of string removed
    children[charVal]->addWord(word.substr(1));
}

bool Trie::isWord(string word) {
    // if we have reached the last node for the word
    if (word.length() == 0) {
        return wordFlag == true;
    }
    // check if current character is not valid
    int charVal = getCharacterIndex(word[0]);
    if (charVal == -1) {
        return false;
    }
    // check if correct child node doesn't exist
    if (children[charVal] == nullptr) {
        return false;
    }
    // recursive call with first (current) character of string removed
    return children[charVal]->isWord(word.substr(1));
}

vector<string> Trie::allWordsStartingWithPrefix(string prefix) {
    int prefixLen = prefix.length();
    // final vector containing all subtree words to return
    vector<string> words;
    // if we are still traversing prefix
    if (prefixLen > 0) {
        int charVal = getCharacterIndex(prefix[0]);
        if (charVal != -1) {
            // get all words in subtree for child node with current character of prefix
            if (children[charVal] != nullptr) {
                // vector containing all nodes in subtree
                words = children[charVal]->allWordsStartingWithPrefix(prefix.substr(1));
                // add the current character to each word in the vector
                for (string& word : words) {
                    word = prefix[0] + word;
                }
            }
        }
    }
    // if no longer traversing prefix
    else {
        // if this Trie is a word, push back empty string
        // so the calling Trie will know to add the corresponding char
        // because each Trie node doesn't store the char it represents
        if (wordFlag) {
            words.push_back("");
        }
        // get all words in subtree for each child node if they aren't a nullptr
        for (unsigned int i = 0; i < N; i++) {
            if (children[i] != nullptr) {
                // vector containing all words in subtree
                vector<string> tempWords = children[i]->allWordsStartingWithPrefix("");
                // need to add the character to each element to get the full word
                // because the nodes don't store the character they represent
                for (string word: tempWords) {
                    words.push_back(char(i + 'a') + word);
                }
            }
        }
    }
    return words;
}


int Trie::getCharacterIndex(char character) {
    int charVal = character - minChar;
    if (charVal < 0 || charVal >= N) {
        return -1;
    }
    return charVal;
}

