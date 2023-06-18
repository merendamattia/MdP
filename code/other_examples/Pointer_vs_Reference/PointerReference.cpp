/*
    g++ -Wall -Wextra PointerReference.cpp -o PointerReference
*/
#include <iostream>

// References and pointers, will reside in the STACK
int main(){
    long value = 5;

    long& r_value = value;
    long* p_value = &value;
    long** p_p_NULL = NULL;

    long* p_wild; // undefined behaviour

    std::cout
        << "Object\t\t| Memory address\t| References/Points to\n"
        << "--------------------------------------------------------------\n"
        << "&r_value\t| "   << &r_value << "\t| "   << r_value << '\n'
        << "*p_value\t| "   << &p_value << "\t| "   << p_value << '\n'
        << "**p_p_NULL\t| "<< &p_p_NULL << "\t| " << p_p_NULL << '\n'
        << "*p_wild\t\t| "  << &p_wild << "\t| "    << p_wild << '\n';
}