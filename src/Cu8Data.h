#ifndef SIGNAL_PROCESSING_SIMULATION_CU8DATA_H
#define SIGNAL_PROCESSING_SIMULATION_CU8DATA_H


class Cu8Data {
private:
    std::ifstream file;
    std::vector<ComplexNumber> samples;
public:
    Cu8Data(const std::string& file);
    ~Cu8Data();

    size_t GetNumberOfSamples() const;
    const std::vector<ComplexNumber>& GetSamples() const;

    void ReadFile();
};


#endif //SIGNAL_PROCESSING_SIMULATION_CU8DATA_H
