#include <iostream>
namespace N {
    struct C {
        C(int){std::cerr<<"\n1";}; // funzione #1
        C(const C&){std::cerr<<"\n2";}; // funzione #2
        void m(){std::cerr<<"\n3";}; // funzione #3
        void m(int){std::cerr<<"\n4";}; // funzione #4
    };
    void f(double d){std::cerr<<"\n5";}; // funzione #5
    void f(const C& c){std::cerr<<"\n6";}; // funzione #6
    void g(int i, double d){std::cerr<<"\n7";}; // funzione #7
    void g(int i, int j){std::cerr<<"\n8";}; // funzione #8
    void h(C* pc){std::cerr<<"\n9";}; // funzione #9
} // namespace N

void f(char){std::cerr<<"\n10";}; // funzione 10
int h(const char* s = 0){std::cerr<<"\n11"; return 0;}; // funzione 11
int h(const N::C* pc){std::cerr<<"\n12"; return 0;}; // funzione 12


int main() {
    N::C c(5); // chiamata A cand: 1,2; util: 1,2; migliore: 1 ok

    f(5); // chiamata B cand: 10; util: 10; migliore: 10; ok

    f(c); // chiamata C cand: 10, 5, 6; util: 6; migliore: 6; ok

    N::f('a'); // chiamata D cand: 5, 6; util: 5; migliore: 5; ok

    // g(5, 3.7); // chiamata E cand: x; util: x; migliore: x; ok

    N::g(2.3, 5); // chiamata F cand: 7, 8; util: 7, 8; migliore: 8; ok

    N::g(5, 2.3); // chiamata G cand: 7, 8; util: 7, 8; migliore: 7; ok

    h(&c); // chiamata H cand: 9, 12; util: 9, 12; migliore: 9; ni

    h(); // chiamata I cand: 11, 12; util: 11; migliore: 11; ok

    // m(&c); // chiamata J cand: 3, 4; util: x; migliore: x; no

    // m(&c); // chiamata J cand: x; util: x; migliore: x;
}
