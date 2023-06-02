#include <iostream>

void f(const char* s) { std::cout << "Funzione #1" << std::endl; }

template <typename T>
void f(T t) 
    { std::cout << "Funzione #2" << std::endl; }

template <typename T>
void f(T t1, T t2)
    { std::cout << "Funzione #3" << std::endl; }

template <typename T, typename U>
void f(T t, U u)
    { std::cout << "Funzione #4" << std::endl; }

template <typename T>
void f(T* pt, T t)
    { std::cout << "Funzione #5" << std::endl; }

template <typename T, typename U>
void f(T* pt, U u)
    { std::cout << "Funzione #6" << std::endl; }

template <typename T>
void g(T t, double d)
    { std::cout << "Funzione #7" << std::endl; }

template <typename T>
void g(T t1, T t2)
    { std::cout << "Funzione #8" << std::endl; }

int main() {
    f('a');     // #2
    f("aaa");   // #1
    
    int i = 0;    
    f(i);       // #2
    f(i, i);    // #3
    f(i, &i);   // #4
    f(&i, i);   // #5

    double d = 0;
    f(i, d);    // #4
    f(&d, i);   // #6
    
    long l = 0;
    g(l, i);    // #7 (promozione: int -> double)
    g(l, l);    // #8
    g(l, d);    // #7
    // g(d, d);    // #7 e #8 -> ambiguo!

    return 0;
}