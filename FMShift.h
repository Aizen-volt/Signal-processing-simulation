#ifndef SIGNAL_PROCESSING_SIMULATION_FMSHIFT_H
#define SIGNAL_PROCESSING_SIMULATION_FMSHIFT_H


class FmShift {
private:
    vector<ComplexNumber> samples;
    vector<ComplexNumber> samplesShifted;
public:
    FmShift(const vector<ComplexNumber>& samples);

    void Shift(long double p);

    const vector<ComplexNumber>& GetSamplesShifted() const;
};


#endif //SIGNAL_PROCESSING_SIMULATION_FMSHIFT_H
