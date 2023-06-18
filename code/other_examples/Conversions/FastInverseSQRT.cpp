/*
	g++ -Wall -Wextra FastInverseSQRT.cpp -o FastInverseSQRT
*/
#include <iostream>

float FastInvSQRT(float x) {
	float xhalf = 0.5f * x; 		// halves the variable 'x'

	int i = *(int *)&x;				// '&x' contains memory address of 'x'
									// '(int *)' is an explicit cast to pointer to integer
									// '*' dereferences the pointer to an integer
	i = 0x5f3759df - (i >> 1);

	x = *(float *)&i;
	x = x * (1.5f - (xhalf * x * x));
	// x = x*(1.5f-(xhalf*x*x));

	return x;
}

int main() {
	std::cout << FastInvSQRT(2) << std::endl;
	return 0;
}
