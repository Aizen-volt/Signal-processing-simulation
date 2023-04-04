#pragma once
#include "ComplexNumber.h"
#include <iostream>
#include <fstream>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class Cu8Data {
private:
	ifstream file;
	vector<ComplexNumber> samples;
public:
	Cu8Data(string file) {
		this->file.open(file, std::ios::binary);
	}


	~Cu8Data() {
		file.close();
	}


	size_t GetNumberOfSamples() const { return samples.size(); }


	vector<ComplexNumber>& GetSamples() { return samples; }


	void ReadFile() {
		vector<unsigned char> buffer(std::istreambuf_iterator<char>(file), {});
		for (int i = 0; i < buffer.size(); i += 2) {
			long double a = (buffer[i] - 127.5) / 127.5;
			long double b = (buffer[i + 1] - 127.5) / 127.5;
			ComplexNumber temp = { a, b };
			samples.push_back(temp);
		}
	}
};