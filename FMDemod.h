#pragma once
#include "ComplexNumber.h"
#include <vector>


class FMDemod {
private:
	std::vector<ComplexNumber> samples;
	std::vector<long double> samplesDemoded;
public:
	FMDemod(const std::vector<ComplexNumber>& samples) {
		this->samples = samples;
	}


	void Demod() {
		for (size_t i = 1; i < samples.size(); i++) {
			ComplexNumber temp2 = samples[i] * samples[i - 1].Conjugate();
			long double arg = temp2.GetArg();
			samplesDemoded.push_back(1.0 / 3.14 * arg);
		}
	}


	const std::vector<long double>& GetSamplesDemoded() const { return samplesDemoded; }
};