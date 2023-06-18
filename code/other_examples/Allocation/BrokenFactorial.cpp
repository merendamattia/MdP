/*
    g++ -Wall -Wextra BrokenFactorial.cpp BrokenFactorial -lgmpxx -lgmp
                                                            ^         ^
                                                            |         |
                                                        C++ wrapper  C wrapper
*/
#include <iostream>
#include <gmpxx.h>

using Integer = mpz_class;

int brokenFact(int n) {
    if (n == 0)
        return 1;
    else
        return n * brokenFact(n-1);
}

Integer fact(Integer n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n-1);
}

int main() { 
    for (int i=0; i<100; ++i) // works to a certain degree, will overflow after a few iterations
        std::cout << "brokenFact(" << i <<") = " << brokenFact(i) << std::endl;
    
    std::cout << "\n---\n" << std::endl;
    
    for (int i=0; i<100; ++i) // uses <gmpxx.h>
        std::cout << "fact(" << i <<") = " << fact(i) << std::endl;
}