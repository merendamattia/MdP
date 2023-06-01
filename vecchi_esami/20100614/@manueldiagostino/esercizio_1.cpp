#include <iostream>

namespace N {
    struct C {
        C(int) {std::cout<<"1"<<std::endl;} // funzione #1
        C(const C&) {} // funzione #2
        void m() {} // funzione #3
        void m(int) {} // funzione #4
    };

    void f(double d) {std::cout<<"5"<<std::endl;} // funzione #5
    void f(const C& c) {std::cout<<"6"<<std::endl;} // funzione #6
    void g(int i, double d) {std::cout<<"7"<<std::endl;} // funzione #7
    void g(int i, int j) {std::cout<<"8"<<std::endl;} // funzione #8
    void h(C* pc) {std::cout<<"9"<<std::endl;} // funzione #9
} // namespace N


void f(char){std::cout<<"10"<<std::endl;} // funzione 10
int h(const char* s = 0){std::cout<<"11"<<std::endl; return 0;} // funzione 11
int h(const N::C* pc){std::cout<<"12"<<std::endl; return 0;} // funzione 12


int main() {
    N::C c(5); // chiamata A CAND{1,2} UTIL{1,2} MIGL{1}
    f(5); // chiamata B CAND{10} UTIL{10} MIGL{10}
    f(c); // chiamata C CAND{5,6,10} UTIL{6} MIGL{6}
    N::f('a'); // chiamata D CAND{5,6} UTIL{5} MIGL{5}
    //g(5, 3.7); // chiamata E CAND{} UTIL{} MIGL{}
    N::g(2.3, 5); // chiamata F CAND{7,8} UTIL{7,8} MIGL{8}
    N::g(5, 2.3); // chiamata G CAND{7,8} UTIL{7,8} MIGL{7}
    h(&c); // chiamata H CAND{11,12,9} UTIL{12,9} MIGL{9}
    h(); // chiamata I CAND{11,12} UTIL{11} MIGL{11}
    //m(&c); // chiamata J CAND{} UTIL{} MIGL{}
}
