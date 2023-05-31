#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() : a(0), b(0) {}


ComplexNumber::ComplexNumber(long double a, long double b) {
    this->a = a;
    this->b = b;
}


//e^(j*2PI*p*n)
void ComplexNumber::Exponential() {
    long double exponent = 2 * 3.14 * a * b;
    a = cos(exponent);
    b = sin(exponent);
}


long double ComplexNumber::GetA() const { return a; }


long double ComplexNumber::GetB() const { return b; }


long double ComplexNumber::GetArg() const { return atan2(b, a); }


ComplexNumber ComplexNumber::Conjugate() const {
    ComplexNumber temp = { a, -b };
    return temp;
}


ComplexNumber ComplexNumber::operator=(long double right) const {
    ComplexNumber temp(right, 0);
    return temp;
}


ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right) {
    long double x1 = left.GetA();
    long double x2 = right.GetA();
    long double y1 = left.GetB();
    long double y2 = right.GetB();
    ComplexNumber temp(x1 + x2, y1 + y2);
    return temp;
}


ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right) {
    long double x1 = left.GetA();
    long double x2 = right.GetA();
    long double y1 = left.GetB();
    long double y2 = right.GetB();
    ComplexNumber temp(x1 - x2, y1 - y2);
    return temp;
}


ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right) {
    long double x1 = left.GetA();
    long double x2 = right.GetA();
    long double y1 = left.GetB();
    long double y2 = right.GetB();
    ComplexNumber temp(x1 * x2 - y1 * y2, x1 * y2 + y1 * x2);
    return temp;
}


ComplexNumber operator*(long double left, const ComplexNumber& right) {
    ComplexNumber temp(left * right.a, left * right.b);
    return temp;
}


ComplexNumber operator/(const ComplexNumber& left, long double right) {
    ComplexNumber temp(left.GetA() / right, left.GetB() / right);
    return temp;
}