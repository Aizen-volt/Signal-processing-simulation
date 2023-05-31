#ifndef SIGNAL_PROCESSING_SIMULATION_COMPLEXNUMBER_H
#define SIGNAL_PROCESSING_SIMULATION_COMPLEXNUMBER_H


class ComplexNumber {
private:
    //z = a + ib
    long double a, b;
public:
    ComplexNumber();
    ComplexNumber(long double a, long double b);

    void Exponential();

    long double GetA() const;
    long double GetB() const;
    long double GetArg() const;

    ComplexNumber Conjugate() const;

    ComplexNumber operator=(long double right);

    friend ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);
    friend ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right);
    friend ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right);
    friend ComplexNumber operator*(long double left, const ComplexNumber& right);
    friend ComplexNumber operator/(const ComplexNumber& left, long double right);
};


#endif //SIGNAL_PROCESSING_SIMULATION_COMPLEXNUMBER_H
