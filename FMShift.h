#pragma once
#include "ComplexNumber.h"
#include <vector>

using std::vector;

class FMShift {
private:
	vector<ComplexNumber> samples;
	vector<ComplexNumber> samplesShifted;
public:
	FMShift(vector<ComplexNumber> samples) {
		for (size_t i = 0; i < samples.size(); i++)
			this->samples.push_back(samples[i]);
	}


	void Shift(long double p) {
		for (size_t i = 0; i < samples.size(); i++) {
			ComplexNumber multiplier = { p, long double(i) };
			multiplier.Exponential();
			ComplexNumber temp = samples[i] * multiplier;
			samplesShifted.push_back(temp);
		}
	}


	vector<ComplexNumber>& GetSamplesShifted() { return samplesShifted; }
};