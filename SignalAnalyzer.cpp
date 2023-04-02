#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using std::fstream;
using std::string;
using std::vector;

class ComplexNumber {
private:
	//z = a+ib
	long double a, b;
public:
	ComplexNumber() : a(0), b(0) {}
	ComplexNumber(long double a, long double b) {
		this->a = a;
		this->b = b;
	}
	//e^(j*2PI*p*n)
	ComplexNumber(double p, size_t n) {
		double exponent = 2 * 3.14 * p * n;
		a = cos(exponent);
		b = sin(exponent);
	}
	long double GetA() const { return a; }
	long double GetB() const { return b; }
	long double GetArg() const { return atan(b / a); }
	friend ComplexNumber& operator+(const ComplexNumber& left, const ComplexNumber& right) {
		ComplexNumber temp(left.GetA() + right.GetA(), left.GetB() + right.GetB());
		return temp;
	}
	friend ComplexNumber& operator-(const ComplexNumber& left, const ComplexNumber& right) {
		ComplexNumber temp(left.GetA() - right.GetA(), left.GetB() - right.GetB());
		return temp;
	}
	friend ComplexNumber& operator*(const ComplexNumber& left, const ComplexNumber& right) {
		ComplexNumber temp(left.GetA() * right.GetA() - left.GetB() * right.GetB(), left.GetA() * right.GetA() - left.GetB() * right.GetB());
		return temp;
	}
	friend ComplexNumber& operator/(const ComplexNumber& left, long double right) {
		ComplexNumber temp(left.GetA() / right, left.GetB() / right);
		return temp;
	}
	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& right) {
		os << "z: " << right.GetA() << (right.GetB() >= 0 ? " + " : " - ") << abs(right.GetB()) << "i\n";
		return os;
	}
};

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
		fclose(this->file);
	}
	void SetLength() {
		fseek(this->file, 0, SEEK_END);
		size_t fileLength = ftell(this->file);
		rewind(this->file);
	}
	size_t GetNumberOfSamples() const { return samples.size(); }
	vector<ComplexNumber> GetSamples() { return samples; }
	void ReadFile() {
		char* buffer = (char*)malloc((fileLength + 1) * sizeof(char));
		for (size_t i = 0; i < fileLength; i++) {
			fread(buffer + i, 1, 1, this->file);
		}
		CreateSamples(buffer);
		free(buffer);
	}
	void CreateSamples(char* buffer) {
		for (size_t i = 0; i < fileLength; i += 2) {
			double temp1 = (buffer[i] - 127.5) / 127.5;
			double temp2 = (buffer[i + 1] - 127.5) / 127.5;
			ComplexNumber temp(temp1, temp2);
			samples.push_back(temp);
		}
	}
};

class FMShift {
private:
	vector<ComplexNumber> samples;
	vector<ComplexNumber> samplesShifted;
public:
	FMShift(vector<ComplexNumber> samples) {
		for (size_t i = 0; i < samples.size(); i++)
			this->samples.push_back(samples[i]);
	}
	void Shift(double p) {
		for (size_t i = 0; i < samples.size(); i++) {
			ComplexNumber multiplier(p, i);
			ComplexNumber temp = samples[i] * multiplier;
			samplesShifted.push_back(temp);
			std::cout << temp << " ";
		}
	}
};

int main() {
	/*fstream file;
	file.open("fm1_99M726_1M92.cu8", fstream::binary);
	while (!file.eof()) {
		string temp;
		file >> temp;
		std::cout << temp << "\n";
	}*/

	Cu8Data input("fm1_99M726_1M92.cu8");
	FMShift shift(input.GetSamples());
	shift.Shift(-0.090625);

	//file.close();
	return 0;
}