/*
Name: Alex Gilsoul
Class: CS 3505
Assignment: 3 - Facades and Makefiles
Description: Header file for a Sine wave class, taken from Assignment 2
*/

#ifndef SINE_H
#define SINE_H

#include <iostream>
#include <cmath>  // included this because I need M_PI for the conversion factor


const double ANGLE_RADIAN_CONVERSION_FACTOR {M_PI / 180};  // used for converting from degrees to radians


class Sine {
    double amplitude;
    double wavelength;
    double angle{0};
    double angleIncrement;
public:
    /// @brief Constructs Sine object
    /// @param amplitude amplitude of sine wave
    /// @param wavelength wavelength of sine wave
    /// @param angleIncrement angle increment to be applied on ++ operations
    Sine(double amplitude, double wavelength, double angleIncrement);
    /// @brief Getter for current angle
    /// @return the current angle
    const double currentAngle();
    /// @brief Getter for the current height
    /// @return sin(angle)
    const double currentHeight();
    /// @brief Overloads the ++ prefix operator, adds angle increment to angle
    /// @return Reference to this Sine object
    Sine& operator++();
    /// @brief Overloads the ++ postfix operator, makes copy of this object, adds angle increment to angle of this object
    /// @param i this doesn't serve a purpose
    /// @return Copy of this object
    Sine operator++(int i);
    /// @brief Overloads the << operator for outputting to a stream
    /// @param out stream we are outputting to
    /// @param sine the Sine object we are sending to the stream
    /// @return the stream we outputted to
    friend std::ostream& operator<<(std::ostream& out, Sine sine);
};

#endif