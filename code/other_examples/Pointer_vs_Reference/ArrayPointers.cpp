/*
    g++ -Wall -Wextra ArrayPointers.cpp -o ArrayPointers
*/
#include <iostream>

int main() {
    int anArray[5] = {0,1,2,3,4};

    std::cout << "\t--- First element of 'anArray' ---\t" << std::endl;
    int* aPointer = anArray; // aPointer = &anArray[0];
    std::cout << aPointer << " = " << anArray << '\n' << std::endl;

    std::cout << "\t--- Pointer dereference iteration ---\t\n"
        << "memory_address\t| value\t|" << std::endl;
    for(int i = 0; i<5; i++)
        std::cout << aPointer + i << "\t| " 
            << *(aPointer + i) << "\t|" << std::endl;
    
    std::cout << "\n\t--- Pointer based iteration ---\t\n" 
        << "memory_address\t| value\t|" << std::endl;
    for(int* p = anArray; p != anArray+5; ++p)
        std::cout << p << "\t| "
            << *p << "\t|" << std::endl;

    return EXIT_SUCCESS;
}