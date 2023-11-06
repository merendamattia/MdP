/*
    g++ -Wall -Wextra MaxInt.cpp -o MaxInt
*/
#include <iostream>
#include <limits>

/*
    type    | lowest()      | min()         | max()
    int     | -2147483648   | -2147483648   | 2147483647
*/
int main() {
	std::cout 
		<< "type\t| lowest()\t| min()\t\t| max()\n"
		<< "int\t| "
		<< std::numeric_limits<int>::lowest() << "\t| "
		<< std::numeric_limits<int>::min() << "\t| "
		<< std::numeric_limits<int>::max() << '\n';
}