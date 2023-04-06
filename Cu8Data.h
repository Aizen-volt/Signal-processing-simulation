#pragma once
#include "ComplexNumber.h"
#include <iostream>
#include <fstream>
#include <vector>

class Cu8Data {
private:
	std::ifstream file;
	std::vector<ComplexNumber> samples;
public:
	Cu8Data(const std::string& file) {
		this->file.open(file, std::ios::binary);
	}


	~Cu8Data() {
		file.close();
	}


	size_t GetNumberOfSamples() const { return samples.size(); }


	const std::vector<ComplexNumber>& GetSamples() const { return samples; }


	void ReadFile() {
		std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(file), {});

		for (size_t i = 0; i < buffer.size(); i += 2) {
			long double a = (buffer[i] - 127.5) / 127.5;
			long double b = (buffer[i + 1] - 127.5) / 127.5;
			ComplexNumber temp = { a, b };
			samples.push_back(temp);
		}
	}
};