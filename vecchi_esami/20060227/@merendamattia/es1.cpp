#include <iostream>

void foo(int*) { std::cout << "Funzione #1" << std::endl; }

template <typename T>
void foo(const T&) { std::cout << "Funzione #2" << std::endl; }

template <typename T>
void foo(T, T) { std::cout << "Funzione #3" << std::endl; }

template <typename T, typename U>
void foo(T, U) { std::cout << "Funzione #4" << std::endl; }

template <typename T>
void foo(const T*, T) { std::cout << "Funzione #5" << std::endl; }

template <typename T, typename U>
void foo(T*, U) { std::cout << "Funzione #6" << std::endl; }

namespace A {
    struct Delta {
        Delta(double = 0) {};
    };
    template <typename T>
    void bar(T, double) { std::cout << "Funzione #7" << std::endl; }

    template <typename T, typename U>
    void bar(T, U) { std::cout << "Funzione #8" << std::endl; }
} // namespace A

template <typename T>
void bar(T, const A::Delta&) { std::cout << "Funzione #9" << std::endl; }

int main() {
    int alfa;
    double beta;
    long gamma;

    const int* p_alfa = &alfa;

    A::Delta delta;
    
    foo(&alfa, beta);               // chiamata A
    foo(&alfa, alfa);               // chiamata B
    foo(p_alfa, alfa);              // chiamata C
    foo(alfa, p_alfa);              // chiamata D
    
    foo(alfa);                      // chiamata E
    foo(&alfa);                     // chiamata F
    foo(p_alfa);                    // chiamata G
    foo(const_cast<int*>(p_alfa));  // chiamata H

    bar(gamma, gamma);              // chiamata I
    bar(delta, alfa);               // chiamata L
    bar(delta, beta);               // chiamata M
    A::bar(beta, gamma);            // chiamata N

    return 0;
}

/*
a) CAND:4,5,6   UTIL:4,6    BEST:6 
b) CAND:4,5,6   UTIL:4,6    BEST:6
c) CAND:5       UTIL:5      BEST:5
d) CAND:4       UTIL:4      BEST:4
e) CAND:1,2     UTIL:2      BEST:2
f) CAND:1,2     UTIL:1      BEST:1
g) CAND:1,2     UTIL:1,2    BEST:2 (perchè p_alfa è const)
h) CAND:1,2     UTIL:1,2    BEST:1 (perchè `rimuovo` il const con il cast)
i) CAND:9       UTIL:9      BEST:9
l) CAND:7,8     UTIL:8      BEST:8
m) CAND:7,8     UTIL:7,8    BEST:7 (ambiguo)
n) CAND:7,8     UTIL:8      BEST:8
*/