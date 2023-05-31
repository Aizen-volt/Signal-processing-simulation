#ifndef SIGNAL_PROCESSING_SIMULATION_DECIMATE_H
#define SIGNAL_PROCESSING_SIMULATION_DECIMATE_H

template <typename T>
class Decimate {
private:
    std::vector<T> samples;
    std::vector<T> samplesDecimated;
public:
    Decimate(const vector<T>& samples);

    void Average(int p);

    const std::vector<T>& GetSamplesDecimated() const;
};


#endif //SIGNAL_PROCESSING_SIMULATION_DECIMATE_H
