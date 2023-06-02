#include <iostream>

void stampa(const char* s) { std::cout << s << std::endl;}

void foo(int*) { stampa("f1"); }

template <typename T>
void foo(const T&) { stampa("f2"); }

template <typename T>
void foo(T, T) { stampa("f3"); }

template <typename T, typename U>
void foo(T, U) { stampa("f4"); }

template <typename T>
void foo(const T*, T) { stampa("f5"); }

template <typename T, typename U>
void foo(T*, U) { stampa("f6"); }




namespace A {

struct Delta {
    Delta(double = 0) {};
};

template <typename T>
void bar(T, double) { stampa("f7"); }

template <typename T, typename U>
void bar(T, U) { stampa("f8"); }

} // namespace A


template <typename T>
void bar(T, const A::Delta&) { stampa("f9"); }


int main() {

    int alfa;
    const int* p_alfa = &alfa;
    double beta;
    long gamma;
    A::Delta delta;

    // int*, double
    foo(&alfa, beta); // A cand{1,4,6} util{4,6} migl{6}
    // int*, int
    foo(&alfa, alfa); // B cand{1,4,5,6} util{4,5,6} migl{6} --- perche 6 e non 5? --> corrispondenza esatta sul primo argomento
    // const int*, int
    foo(p_alfa, alfa); // C cand{1,4,5,6} util{4,5,6} migl{5}
    // int, const int*
    foo(alfa, p_alfa); // D cand{1,4} util{4} migl{4}
    foo(alfa); // E cand{1,2} util{2} migl{2}
    foo(&alfa); // F cand{1} util{1} migl{1}
    foo(p_alfa); // G cand{1,2} util{2} migl{2}
    foo(const_cast<int*>(p_alfa)); // H cand{1} util{1} migl{1}
    
    // long, long
    bar(gamma, gamma); // I cand{9} util{9} migl{9}
    bar(delta, alfa); // L cand{9,8} util{9,8} migl{8} --- perche 8 e non 9? --> corrispondenza esatta sul secondo argomento
    bar(delta, beta); // M cand{9,8,7} util{9,8,7} migl{7}
    A::bar(beta, gamma); // N cand{8} util{8} migl{8}
    // chiamata A
    // chiamata B
    // chiamata C
    // chiamata D
    // chiamata E
    // chiamata F
    // chiamata G
    // chiamata H
    // chiamata I
    // chiamata L
    // chiamata M
    // chiamata N 
}
