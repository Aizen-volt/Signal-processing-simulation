#include "Cu8Data.h"
#include "FMShift.h"
#include "Decimate.h"
#include "FMDemod.h"
#include "Au.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>


int main() {
    const std::string fileName = "fm1_99M726_1M92.cu8";
    const std::string outputFileName = "output.au";
    const long double FMShiftParameter = -0.090625;
    const int Decimate1Parameter = 5;
    const int Decimate2Parameter = 8;

    auto start = std::chrono::system_clock::now();

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

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << '\n';

    return 0;
}