/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 1 - 1D Cellular Automata
Description: Given a ruleset number, computes 50 generations of cellular automata.
*/

#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


void convertRuleSetNumberToRuleSetArray(int ruleSet, int array[8]);
void displayCurrentGeneration(int arr[], int n);
void computeNextGeneration(int curGen[], int nexGen[], int n, int ruleSetArray[8]);
int convertNeighborhoodToIndex(int left, int cur, int right);


int main() {
    // Stores rule set number
    int ruleSet;
    // used for getline input
    string input;
    cout << "Enter ruleset number: ";

    try {
        // get user input
        getline(cin, input);
        // convert to number
        ruleSet = stoi(input);
        // if ruleset is outside of range
        if (0 > ruleSet || ruleSet > 255) {
            cout << "Ruleset outside of range" << endl;
            return 0;
        }
    }
    // if a number is not entered as input
    catch (...) {
        cout << "Invalid number input: \"" << input << "\"" << endl;
        return 0;
    }

    // declare binary ruleset array
    int ruleSetArray[8];
    // convert ruleset number to binary ruleset array
    convertRuleSetNumberToRuleSetArray(ruleSet, ruleSetArray);

    // declare initial generation arrays
    int curGen[64] { 0 };
    int nexGen[64];
    curGen[32] = 1;

    // display initial generation
    displayCurrentGeneration(curGen, 64);
    // compute next generation 49 times, and display to console
    for (int i = 0; i < 49; i++) {
        computeNextGeneration(curGen, nexGen, 64, ruleSetArray);
        // copy new generation to current generation
        for (int i = 0; i < 64; i++) {
            curGen[i] = nexGen[i];
        }
        displayCurrentGeneration(nexGen, 64);
    }

}


// converts an integer number into a binary array
void convertRuleSetNumberToRuleSetArray(int ruleSet, int array[8]) {
    for (int i = 0; i < 8; i++) {
        if (ruleSet % 2 == 1) array[i] = 1;
        else array[i] = 0;
        ruleSet /= 2;
    }
}


// outputs binary array to console
void displayCurrentGeneration(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cout << " ";
        else cout << "#";
    }
    cout << endl;
}


// compute next generation based on current generation and ruleset
void computeNextGeneration(int curGen[], int nexGen[], int n, int ruleSetArray[8]) {
    // propagate first and last cells
    nexGen[0] = curGen[0];
    nexGen[n-1] = curGen[n-1];
    // do stuff here
    for (int i = 1; i < n-1; i++) {
        nexGen[i] = ruleSetArray[convertNeighborhoodToIndex(curGen[i-1], curGen[i], curGen[i+1])];
    }
}


// convert current cell and neighbors to ruleset index
int convertNeighborhoodToIndex(int left, int cur, int right) {
    return left*4 + cur*2 + right;
}