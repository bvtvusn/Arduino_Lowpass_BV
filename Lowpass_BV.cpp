#include "Arduino.h"
#include "Lowpass_BV.h"

Lowpass_BV::Lowpass_BV(float timeStep, float timeConstant) {
    _timeStep = timeStep;
    _timeConstant = timeConstant;
    _filterCoefficient = _timeStep / (_timeConstant + _timeStep);
    _previousOutput = 0.0;
}

float Lowpass_BV::update(float input) {
    float output = (1 - _filterCoefficient) * _previousOutput + _filterCoefficient * input;
    _previousOutput = output;
    return output;
}

float Lowpass_BV::getOutput() {
    return _previousOutput;
}
float Lowpass_BV::getFilterCoefficient() {
    return _filterCoefficient;
}