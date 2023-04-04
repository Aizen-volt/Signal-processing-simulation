#pragma once
#include <vector>
#include <fstream>

using std::ofstream;
using std::vector;
using std::string;

class Au {
private:
	ofstream file;
	vector<long double> samples;
public:
	Au(string file, vector<long double> samples) {
		this->file.open(file, std::ios::binary);
		for (size_t i = 0; i < samples.size(); i++) {
			this->samples.push_back(float(samples[i]));
		}
	}


	~Au() {
		file.close();
	}


	void GenerateFile() {
		__int32 snd = 0x2e736e64;
		__int32 headerLength = 24;
		__int32 unknownSamplesNumber = 0xffffffff;
		__int32 float32 = 6;
		__int32 samplesFrequency = 48000;
		__int32 channel = 1;
		file.write((char*)&snd, sizeof(float));
		file.write((char*)&headerLength, sizeof(float));
		file.write((char*)&unknownSamplesNumber, sizeof(float));
		file.write((char*)&float32, sizeof(float));
		file.write((char*)&samplesFrequency, sizeof(float));
		file.write((char*)&channel, sizeof(float));
		for (size_t i = 0; i < samples.size(); i++) {
			float sample = samples[i];
			file.write((char*) & sample, sizeof(float));
		}
	}
};