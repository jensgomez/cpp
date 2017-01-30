#pragma once

#include <iostream>
#include <cmath>

class pipe{
	
private:
	double d, e, re, f;
	
public:
	pipe(double, double, double);
	double friction(void);

};

pipe::pipe(double a, double b, double c){
	d = a; e = b; re = c;
}

double pipe::friction(void){
	
	std::cout << "--------- ECHO --------- " << std::endl << std::endl;
	std::cout << "DIAMETER          = " << d << std::endl;
	std::cout << "SURFACE ROUGHNESS = " << e << std::endl;
	std::cout << "REYNOLDS NUMBER   = " << re << std::endl;
	std::cout << std::endl << std::endl;
	
	double a = 1.0e-6; 
    double b = 1.00;
    double c = 0.5*(a+b);

    const int n = 1000000;
    for (int i=0; i<n; i++) {
        double fa = sqrt(a)*(-2.0*log10(e/(d*3.7) + 2.51/(re*sqrt(a)))) - 1.0;
        double fb = sqrt(b)*(-2.0*log10(e/(d*3.7) + 2.51/(re*sqrt(b)))) - 1.0;
        double fc = sqrt(c)*(-2.0*log10(e/(d*3.7) + 2.51/(re*sqrt(c)))) - 1.0;

        // Bisection method
        if (fa*fc > 0) {
            a = c;
        }
        else {
            b = c;
        }
        c = 0.5*(a+b);
    }
    
	return c;
}
