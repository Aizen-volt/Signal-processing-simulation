#ifndef SIGNAL_PROCESSING_SIMULATION_FMDEMOD_H
#define SIGNAL_PROCESSING_SIMULATION_FMDEMOD_H


class FmDemod {
private:
    std::vector<ComplexNumber> samples;
    std::vector<long double> samplesDemoded;
public:
    FmDemod(const std::vector<ComplexNumber>& samples);

    void Demod();

    const std::vector<long double>& GetSamplesDemoded() const;
};


#endif //SIGNAL_PROCESSING_SIMULATION_FMDEMOD_H
