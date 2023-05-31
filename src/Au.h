#ifndef SIGNAL_PROCESSING_SIMULATION_AU_H
#define SIGNAL_PROCESSING_SIMULATION_AU_H


class Au {
private:
    const __int32 snd = 0x2e736e64;
    const __int32 headerLength = 24;
    const __int32 unknownSamplesNumber = 0xffffffff;
    const __int32 float32 = 6;
    const __int32 samplesFrequency = 48000;
    const __int32 channel = 1;

    std::ofstream file;
    std::vector<long double> samples;

    void GenerateHeader();
public:
    Au(const std::string& file, const std::vector<long double>& samples);
    ~Au();

    void GenerateFile();
};


#endif //SIGNAL_PROCESSING_SIMULATION_AU_H
