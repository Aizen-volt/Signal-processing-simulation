#pragma once
#include "ComplexNumber.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Cu8Data {
private:
	FILE* file;
	size_t fileLength;
	vector<ComplexNumber> samples;
public:
	Cu8Data(string file) {
		this->file = fopen(file.c_str(), "rb");
		SetLength();
		ReadFile();
	}


	~Cu8Data() {
		fclose(file);
	}


	void SetLength() {
		fseek(file, 0L, SEEK_END);
		fileLength = ftell(file);
		rewind(file);
	}


	size_t GetNumberOfSamples() const { return samples.size(); }


	vector<ComplexNumber>& GetSamples() { return samples; }


	void ReadFile() {
		char* buffer = new char[fileLength + 1];
		for (size_t i = 0; i < fileLength; i++) {
			fread(buffer + i, 1, 1, this->file);
		}
		CreateSamples(buffer);
		delete[] buffer;
	}


	void CreateSamples(char* buffer) {
		for (size_t i = 0; i < fileLength; i += 2) {
			long double temp1 = (long double(buffer[i]) - 127.5) / 127.5;
			long double temp2 = (long double(buffer[i + 1]) - 127.5) / 127.5;
			ComplexNumber temp(temp1, temp2);
			samples.push_back(temp);
		}
	}
};