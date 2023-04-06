#pragma once
#include <vector>

template <typename T>
class Decimate {
private:
	std::vector<T> samples;
	std::vector<T> samplesDecimated;
public:
	Decimate(const vector<T>& samples) {
		this->samples = samples;
	}


	void Average(int p) {
		for (size_t i = p - 1; i < samples.size(); i += p) {
			T sum;
			sum = 0.0;
			for (size_t j = 0; j < p; j++) {
				T temp = samples[i - j] / (double)p;
				sum = sum + temp;
			}
			samplesDecimated.push_back(sum);
		}
	}

	const std::vector<T>&GetSamplesDecimated() const { return samplesDecimated; }
};