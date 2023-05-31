#include "Decimate.h"

template <typename T>
Decimate::Decimate(const vector<T>& samples) {
    this->samples = samples;
}

template <typename T>
void Decimate::Average(int p) {
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

template <typename T>
const std::vector<T>& Decimate::GetSamplesDecimated() const { return samplesDecimated; }