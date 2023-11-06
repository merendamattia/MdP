/*
    g++ -Wall -Wextra Overloading.cpp -o Overloading
*/
#include <iostream>

void f(const char* s) { std::cout << "function #1" << std::endl; };  // function #1
template <typename T>
void f(T t) { std::cout << "function #2" << std::endl; };            // function #2

template <typename T>
void f(T t1, T t2) { std::cout << "function #3" << std::endl; };     // function #3
template <typename T, typename U>
void f(T t, U u) { std::cout << "function #4" << std::endl; };       // function #4
template <typename T>
void f(T* pt, T t) { std::cout << "function #5" << std::endl; };     // function #5
template <typename T, typename U>
void f(T* pt, U u) { std::cout << "function #6" << std::endl; };     // function #6

template <typename T>
void g(T t, double d) { std::cout << "function #7" << std::endl; };  // function #7
template <typename T>
void g(T t1, T t2) { std::cout << "function #8" << std::endl; };     // function #8

int main(){
    f('a');     // call #1
    f("aaa");   // call #2
    int i;
    f(i);       // call #3
    f(i, i);    // call #4
    f(i, &i);   // call #5
    f(&i, i);   // call #6
    double d;
    f(i, d);    // call #7
    f(&d, i);   // call #8
    long l;
    g(l, i);    // call #9
    g(l, l);    // call #10
    g(l, d);    // call #11
    //g(d, d);  // ambiguous

    return 0;
}