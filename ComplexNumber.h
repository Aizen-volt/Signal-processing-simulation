#pragma once
#include <iostream>
#include <cmath>

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
	void Exponential() {
		long double exponent = 2 * 3.14 * a * b;
		a = cos(exponent);
		b = sin(exponent);
	}
	long double GetA() const { return a; }
	long double GetB() const { return b; }
	long double GetArg() const { return atan2(b, a); }
	ComplexNumber Conjugate() {
		ComplexNumber temp = { a, -b };
		return temp;
	}
	ComplexNumber& operator=(long double right) {
		ComplexNumber temp(right, 0);
		return temp;
	}
	friend ComplexNumber& operator+(const ComplexNumber& left, const ComplexNumber& right) {
		ComplexNumber temp(left.GetA() + right.GetA(), left.GetB() + right.GetB());
		return temp;
	}
	friend ComplexNumber& operator-(const ComplexNumber& left, const ComplexNumber& right) {
		ComplexNumber temp(left.GetA() - right.GetA(), left.GetB() - right.GetB());
		return temp;
	}
	friend ComplexNumber& operator*(const ComplexNumber& left, const ComplexNumber& right) {
		ComplexNumber temp(left.GetA() * right.GetA() - left.GetB() * right.GetB(), left.GetA() * right.GetB() - left.GetB() * right.GetA());
		return temp;
	}
	friend ComplexNumber& operator*(long double left, const ComplexNumber& right) {
		ComplexNumber temp(left * right.a, left * right.b);
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