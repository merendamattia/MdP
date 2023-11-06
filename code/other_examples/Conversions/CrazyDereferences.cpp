/*
    g++ -Wall -Wextra CrazyDereferences.cpp -o CrazyDereferences 
*/
#include <iostream>
#include <typeinfo>
#include <iomanip>

/*  This essentially converts the memory address to an integer
    - &x is a variable holding the memory address of x
    - (int *) casts the variable &x to an integer pointer
    - * dereferences the pointer to an integer
*/
template<typename T>
void CrazyDereferences(T x){
    std::cout << "'x' is of type: " << typeid(x).name() << std::endl;

    int i = *(int *)&x;
    double d = *(double *)&x;
    float f = *(float *)&x;

    std::cout << // exact conversion lead to consistent values for 'Value' and 'x'
        "┌──────────┬───────────────┬───────────────────┬───────────────┬───────────────────┐\n"
        "│ Variable │     Value     │      Address      │       x       │      Address      │\n"
        "├──────────┼───────────────┼───────────────────┼───────────────┼───────────────────┤\n";
    std::cout << std::left <<
        "│ " << std::setw(9) << "i" << "│ " << std::setw(14) << i << "│ " << std::setw(18) << &i << "│ " << std::setw(14) << x << "│ " << std::setw(18) << &x << "│" << std::endl <<
        "│ " << std::setw(9) << "d" << "│ " << std::setw(14) << d << "│ " << std::setw(18) << &d << "│ " << std::setw(14) << x << "│ " << std::setw(18) << &x << "│" << std::endl <<
        "│ " << std::setw(9) << "f" << "│ " << std::setw(14) << f << "│ " << std::setw(18) << &i << "│ " << std::setw(14) << x << "│ " << std::setw(18) << &x << "│" << std::endl <<
        "└──────────┴───────────────┴───────────────────┴───────────────┴───────────────────┘" << std::endl;
}

int main() {
    CrazyDereferences(10);      // int
    CrazyDereferences(3.5);     // double
    CrazyDereferences(3.1415f); // float
}