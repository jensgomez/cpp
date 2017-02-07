#pragma once
#include <iostream>

class domain1d {
protected:
	double* x;
	int n;

public:
	domain1d(int);
	~domain1d(void);
	void print(void);

};

domain1d::domain1d(int a) {
	n = a;
	x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0.0;
	}
}

void domain1d::print(void) {
	for (int i = 0; i < n; i++) {
		std::cout << x[i] << std::endl;
	}
	std::cout << std::endl;
}

domain1d::~domain1d(void) {
	delete[]x;
}


class boundary : public domain1d {
public:
	boundary(double a, double b) : domain1d(n), x0(a), xn(b) {}
	void bcprint(void);
	// Create a function to set x(0) = x0 and x(n) = xn

private:
	double x0, xn;

};




void boundary::bcprint(void) {
	std::cout << x0 << std::endl << xn << std::endl;
}
