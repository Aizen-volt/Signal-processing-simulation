#include "FmDemod.h"

FmDemod::FmDemod(const std::vector<ComplexNumber>& samples) {
    this->samples = samples;
}


void FmDemod::Demod() {
    for (size_t i = 1; i < samples.size(); i++) {
        ComplexNumber temp2 = samples[i] * samples[i - 1].Conjugate();
        long double arg = temp2.GetArg();
        samplesDemoded.push_back(1.0 / 3.14 * arg);
    }
}


const std::vector<long double>& FmDemod::GetSamplesDemoded() const { return samplesDemoded; }