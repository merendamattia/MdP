/*
    g++ -Wall -Wextra Hiding.cpp -o Hiding
*/
#include <iostream>

struct Base {
    int a;
    void foo(int) { std::cout << "I'm Base's foo()" << std::endl; };
};

struct Derived : public Base {
    double a; // hiding of 'Base::a'
    void foo(double) { std::cout << "I'm Derived's foo()" << std::endl; }; // hiding of 'Base::foo()'
};

struct DerivedButBetter : public Base {
    using Base::foo;
    float a; // hiding of 'Base::a'
    void foo(float) { std::cout << "I'm DerivedButBetter's foo()" << std::endl; };
};

void foo() {
    int endl = 42;
    using namespace std;
    cout << "Hello " << endl;
}

int a = 1;

int main() {
    std::cout << a << std::endl; // 1
    int a = 5;
    std::cout << a << std::endl; // 5

    Base B;
    Derived D;
    DerivedButBetter DBB;

    B.foo(1); // Base::foo()
    D.foo(5); // Derived::foo()
    DBB.foo(6); // Base::foo()
    DBB.foo((float)3); // DerivedButBetter::foo()

    foo(); // Hello 42
    
    return 0;
}