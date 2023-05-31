#include "FmShift.h"

FmShift::FmShift(const vector<ComplexNumber>& samples) {
    this->samples = samples;
}


void FmShift::Shift(long double p) {
    for (size_t i = 0; i < samples.size(); i++) {
        ComplexNumber multiplier = { p, long double(i) };
        multiplier.Exponential();
        ComplexNumber temp = samples[i] * multiplier;
        samplesShifted.push_back(temp);
    }
}


const vector<ComplexNumber>& FmShift::GetSamplesShifted() const { return samplesShifted; }