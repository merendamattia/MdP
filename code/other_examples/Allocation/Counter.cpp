/*
    g++ Counter.cpp -o Counter
*/
#include <iostream>

struct S {
    int counter;
    S() : counter(0) {}
    ~S() { std::cout << "Counter is at: " << counter << std::endl; }
};

void foo() {
    static S s;
    ++s.counter;
}

int main() { // Counter is at: 10
    for(int i=0; i<10; ++i)
        foo();
}