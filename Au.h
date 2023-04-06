#pragma once
#include <vector>
#include <fstream>

class Au {
private:
	std::ofstream file;
	std::vector<long double> samples;

	void GenerateHeader() {
		const __int32 snd = 0x2e736e64;
		const __int32 headerLength = 24;
		const __int32 unknownSamplesNumber = 0xffffffff;
		const __int32 float32 = 6;
		const __int32 samplesFrequency = 48000;
		const __int32 channel = 1;

		file.write((char*)&snd, sizeof(float));
		file.write((char*)&headerLength, sizeof(float));
		file.write((char*)&unknownSamplesNumber, sizeof(float));
		file.write((char*)&float32, sizeof(float));
		file.write((char*)&samplesFrequency, sizeof(float));
		file.write((char*)&channel, sizeof(float));
	}
public:
	Au(const std::string& file, const std::vector<long double>& samples) {
		this->file.open(file, std::ios::binary);
		this->samples = samples;
	}


	~Au() {
		file.close();
	}


	void GenerateFile() {
		GenerateHeader();

		for (size_t i = 0; i < samples.size(); i++) {
			float sample = samples[i];
			file.write((char*) & sample, sizeof(float));
		}
	}
};