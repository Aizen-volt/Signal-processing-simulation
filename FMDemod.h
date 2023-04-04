#pragma once
#include "ComplexNumber.h"
#include <vector>

using std::vector;

class FMDemod {
private:
	vector<ComplexNumber> samples;
	vector<long double> samplesDemoded;
public:
	FMDemod(vector<ComplexNumber> samples) {
		for (size_t i = 0; i < samples.size(); i++)
			this->samples.push_back(samples[i]);
	}


	void Demod() {
		for (size_t i = 1; i < samples.size(); i++) {
			ComplexNumber temp1 = samples[i - 1].Conjugate();
			ComplexNumber temp2 = samples[i] * temp1;
			long double arg = temp2.GetArg();
			samplesDemoded.push_back(1.0 / 3.14 * arg);
		}
	}


	vector<long double>& GetSamplesDemoded() { return samplesDemoded; }
};