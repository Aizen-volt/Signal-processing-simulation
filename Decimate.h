#pragma once
#include <vector>

using std::vector;

template <typename T>
class Decimate {
private:
	vector<T> samples;
	vector<T> samplesDecimated;
public:
	Decimate(vector<T> samples) {
		for (size_t i = 0; i < samples.size(); i++)
			this->samples.push_back(samples[i]);
	}


	void Average(int p) {
		for (size_t i = p - 1; i < samples.size(); i += p) {
			T sum;
			sum = 0.0;
			for (size_t j = 0; j < p; j++) {
				T temp = samples[i - j];
				temp = temp / (double)p;
				sum = sum + temp;
			}
			samplesDecimated.push_back(sum);
		}
	}

	vector<T>& GetSamplesDecimated() { return samplesDecimated; }
};