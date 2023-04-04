#pragma once
#include <vector>

using std::vector;

class Decimate {
private:
	vector<ComplexNumber> complexSamples;
	vector<ComplexNumber> complexSamplesDecimated;
	vector<long double> doubleSamples;
	vector<long double> doubleSamplesDecimated;
public:
	Decimate(vector<ComplexNumber> samples) {
		for (size_t i = 0; i < samples.size(); i++)
			this->complexSamples.push_back(samples[i]);
	}
	Decimate(vector<long double> samples) {
		for (size_t i = 0; i < samples.size(); i++)
			this->doubleSamples.push_back(samples[i]);
	}

	void AverageComplex(int p) {
		for (size_t i = p; i < complexSamples.size(); i += p) {
			ComplexNumber sum = { 0, 0 };
			for (size_t j = 0; j < p; j++) {
				ComplexNumber temp = complexSamples[i - j];
				temp = temp / long double(p);
				sum = sum + temp;
			}
			complexSamplesDecimated.push_back(sum);
		}
	}

	void AverageDouble(int p) {
		for (size_t i = p; i < doubleSamples.size(); i += p) {
			long double sum = 0;
			for (size_t j = 0; j < p; j++) {
				sum = sum + doubleSamples[i - j] / long double(p);
			}
			doubleSamplesDecimated.push_back(sum);
		}
	}


	vector<ComplexNumber>& GetComplexSamplesDecimated() { return complexSamplesDecimated; }
	vector<long double>& GetDoubleSamplesDecimated() { return doubleSamplesDecimated; }
};