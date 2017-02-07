// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"    // Dont need if using non-VS studio compiler
#include "Header1.h"


int main()
{
	domain1d x(10);
	x.print();
	boundary b(2.0, -1.0);
	b.bcprint();
	

	

    return 0;
}

