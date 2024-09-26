/*
Name: Alex Gilsoul
Class: CS 3505
Assignment: 3 - Facades and Makefiles
Description: Implementation file for the Sine wave class, taken from Assignment 2
*/

#include "Sine.h"
#include <cmath>
#include <iostream>

Sine::Sine(double amplitude, double wavelength, double angleIncrement) : amplitude(amplitude), wavelength(wavelength), angleIncrement(angleIncrement) { }

const double Sine::currentAngle() {
    return angle;
}

const double Sine::currentHeight() {
    // convert angle and wavelength to radians
    double angleInRads = angle * ANGLE_RADIAN_CONVERSION_FACTOR;
    double wavelengthInRads = wavelength * ANGLE_RADIAN_CONVERSION_FACTOR;
    // Sine formula
    return amplitude * sin(2 * M_PI * angleInRads / wavelengthInRads);
}

Sine& Sine::operator++() {
    angle += angleIncrement;
    return *this;
}

Sine Sine::operator++(int i) {
    Sine newSine(amplitude, wavelength, angleIncrement);
    ++(*this);
    return newSine;
}

std::ostream& operator<<(std::ostream& out, Sine sine) {
    out << sine.angle << ", " << sine.currentHeight();
    return out;
}