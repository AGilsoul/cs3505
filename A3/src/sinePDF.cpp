/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 3 - Facades and Makefiles
Description: This file uses both the Sine and HaruPDF classes to draw
text in the shape of a sine wave on a PDF file.
*/


#include "HaruPDF.h"
#include "Sine.h"

// output file name
const char* FILENAME = "sinePDF.pdf";

/// @brief main function, called when executable is run
/// @param argc number of arguments in command line
/// @param argv command line arguments
/// @return return code
int main (int argc, char **argv)
{
    // Make sure we have the right number of arguments
    if (argc != 2) {
        std::cout << "Please provide one word, or a string of words contained in single quotes!" << std::endl;
        return 0;
    }
    // convert command line input to a string
    std::string text(argv[1]);

    int textLength = text.length();

    // compute wavelength, angle increment, and fontsize to produce
    // a nicely formatted sine wave with three crests 
    int amplitude = HALFHEIGHT / 5;
    int waveLength = HALFWIDTH * 2 / 3;
    int angleInc = waveLength * 3 / textLength;
    int fontSize = HALFWIDTH * 2 / textLength;

    // create Sine wave object and HaruPDF wrapper object
    Sine sineWave(amplitude, waveLength, angleInc);
    HaruPDF haruWrapper;

    // adjust font size to fit text
    haruWrapper.setFontSize(fontSize);

    for (int i = 0; i < textLength; i++) {
        // get current coordinates on sine wave, shift y up to middle of page
        int x = sineWave.currentAngle();
        int y = sineWave.currentHeight() + HALFHEIGHT;
        // place current character at x and y coordinates
        haruWrapper.placeText(x, y, text[i]);
        // increment sine wave
        sineWave++;
    }
    
    // save file and return
    const char* fileName = FILENAME;
    haruWrapper.save(fileName);
    return 0;
}



