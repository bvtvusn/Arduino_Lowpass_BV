#ifndef Lowpass_BV_h
#define Lowpass_BV_h

#include "Arduino.h"

class Lowpass_BV {
public:
    // Constructor
    Lowpass_BV(float timeStep, float timeConstant);

    // Function to update the filter with a new input
    float update(float input);

    // Function to get the current output
    float getOutput();
	// Function to get the filter coefficient
    float getFilterCoefficient();

private:
    float _timeStep;
    float _timeConstant;
    float _filterCoefficient;
    float _previousOutput;
};

#endif
