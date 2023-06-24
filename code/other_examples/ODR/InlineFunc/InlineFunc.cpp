/*
    g++ -c InlineFunc.cpp -o InlineFunc.o && nm -C InlineFunc.o
    g++ -Wall -Wextra InlineFunc.cpp -o InlineFunc
*/
#include "InlineFunc.hh"
#include <iostream>

int main() {
    ++counter;
    
    if (counter == 1)
        std::cout << "Variable counter = " << counter << std::endl;
    std::cout << "The sum is " << int_sum(1,3) << ", the subtraction is " << int_sub(1,3) << std::endl;
}