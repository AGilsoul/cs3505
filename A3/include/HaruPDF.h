/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 3 - Facades and Makefiles
Description: This is the header file for the HaruPDF wrapper class, which wraps the Haru PDF
library into an easier to use class for our purposes.
*/

#ifndef HARUPDF_H
#define HARUPDF_H

#include <iostream>
#include "hpdf.h"


// constants for page and default font size
const int HALFWIDTH = 504;
const int HALFHEIGHT = 306;
const int DEFAULTFONTSIZE = 20;
const int MAXFONT = 500;

/// @brief HaruPDF basic wrapper class for Haru PDF library
class HaruPDF {
private:
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;

public:
    /// @brief Constructor for HaruPDF wrapper class, initializes member variables
    HaruPDF();
    /// @brief Places a char at a given x and y coordinate on the pdf
    /// @param x x coordinate
    /// @param y y coordinate
    /// @param text character to be placed
    void placeText(int x, int y, char text);
    /// @brief Saves the PDF file
    /// @param fileName name of the PDF to save
    void save(const char* fileName);
    /// @brief Sets the font size of text on the PDF
    /// @param fontSize font size to be set
    void setFontSize(int fontSize);
};

#endif