/*
Name: Alex Gilsoul
Class: CS 3505
Assignment: 2 - Making a Class
Description: Tests the implementation of the Sine class.
*/

#include "Sine.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Sine sine(1.5, 720, 15.0);
    for (int i = 0; i < 361; i++) {
        cout << sine << endl;
        sine++;
    }
    return 0;
}