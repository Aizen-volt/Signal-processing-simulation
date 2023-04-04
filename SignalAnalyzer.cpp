#define _CRT_SECURE_NO_WARNINGS

#include "Cu8Data.h"
#include "FMShift.h"
#include "Decimate.h"
#include "FMDemod.h"
#include "Au.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <climits>

using std::string;

int main() {
	char static_assert_float32[1 - (2 * ((sizeof(float) * CHAR_BIT) != 32))];

	const string fileName = "fm1_99M726_1M92.cu8";
	const string outputFileName = "output.au";
	const long double FMShiftParameter = -0.090625;
	const int Decimate1Parameter = 5;
	const int Decimate2Parameter = 8;

	Cu8Data input(fileName);
	input.ReadFile();

	FMShift shift(input.GetSamples());
	shift.Shift(FMShiftParameter);

	Decimate<ComplexNumber> decimate1(shift.GetSamplesShifted());
	decimate1.Average(Decimate1Parameter);

	FMDemod demod(decimate1.GetSamplesDecimated());
	demod.Demod();

	Decimate<long double> decimate2(demod.GetSamplesDemoded());
	decimate2.Average(Decimate2Parameter);

	Au au(outputFileName, decimate2.GetSamplesDecimated());
	au.GenerateFile();

	return 0;
}