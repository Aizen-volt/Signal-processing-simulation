#include "Au.h"

Au::Au(const std::string& file, const std::vector<long double>& samples) {
    this->file.open(file, std::ios::binary);
    this->samples = samples;
}


Au::~Au() {
    file.close();
}


void Au::GenerateFile() {
    GenerateHeader();

    for (size_t i = 0; i < samples.size(); i++) {
        float sample = samples[i];
        file.write((char*) & sample, sizeof(float));
    }
}


void Au::GenerateHeader() {
    file.write((char*)&snd, sizeof(float));
    file.write((char*)&headerLength, sizeof(float));
    file.write((char*)&unknownSamplesNumber, sizeof(float));
    file.write((char*)&float32, sizeof(float));
    file.write((char*)&samplesFrequency, sizeof(float));
    file.write((char*)&channel, sizeof(float));
}