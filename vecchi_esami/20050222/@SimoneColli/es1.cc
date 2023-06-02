#include <iostream>
using namespace std;

void f(const char* s){cerr<<"funzione 1\n";} // funzione #1

template <typename T>
void f(T t){cerr<<"funzione 2\n";} // funzione #2


template <typename T>
void f(T t1, T t2){cerr<<"funzione 3\n";} // funzione #3

template <typename T, typename U>
void f(T t, U u){cerr<<"funzione 4\n";} // funzione #4

template <typename T>
void f(T* pt, T t){cerr<<"funzione 5\n";} // funzione #5

template <typename T, typename U>
void f(T* pt, U u){cerr<<"funzione 6\n";} // funzione #6



template <typename T>
void g(T t, double d){cerr<<"funzione 7\n";} // funzione #7

template <typename T>
void g(T t1, T t2){cerr<<"funzione 8\n";} // funzione #8

int main() {
    f('a'); // chiamata #1
    f("aaa"); // chiamata #2

    int i; 
    
    f(i); // chiamata #3
    f(i, i); // chiamata #4
    f(i, &i); // chiamata #5
    f(&i, i); // chiamata #6
    
    double d;
    
    f(i, d); // chiamata #7
    f(&d, i); // chiamata #8
    
    long l;
    
    g(l, i); // chiamata #9
    g(l, l); // chiamata #10
    g(l, d); // chiamata #11
    // g(d, d);// chiamata #12
    return 0;
}