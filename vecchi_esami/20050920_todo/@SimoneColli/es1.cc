#include <string>
#include <iostream>
class D;

class C {
    private:
    // ...
    public:
        C() {}
        C(const D&) {}
        // ...
};
class D {
    private:
        // ...
    public:
        D() {}
        D(const C&) {}
        // ...
};

void f(double d){std::cerr<<"funzione 1\n";}// funzione #1
void f(int i, C c = C()){std::cerr<<"funzione 2\n";}// funzione #2
void f(double d, C c = C()){std::cerr<<"funzione 3\n";}// funzione #3

// ----
void g(C c, D d){std::cerr<<"funzione 4\n";}// funzione #4
void g(D d, C c = C()){std::cerr<<"funzione 5\n";}// funzione #5

// ----
void h(const char* s){std::cerr<<"funzione 6\n";}// funzione #6
void h(const std::string& s){std::cerr<<"funzione 7\n";}// funzione #7



int main() {
    C c;
    D d;

    f('a');// chiamata #1
    f('a', c);// chiamata #2
    // f(3.2);// chiamata #3

    // --- 

    g(c, d);// chiamata #4
    g(d, c);// chiamata #5
    g(c);// chiamata #6
    g(d);// chiamata #7

    // --- 


    h("abra");// chiamata #8
    // h('a');// chiamata #9
}


/*
    candidate   utilizzabili    migliore    correzione

1.  {1, 2, 3}   {1, 3}          {1}         {2}
2.  {1, 2, 3}   {2, 3}          {3}         {2}
3.  {1, 2, 3}   {2, 3}          Ambiguo

4.  {4, 5}      {4}             {4}
5.  {4, 5}      {5}             {5}
6.  {4, 5}      {5}             {5}
7.  {4, 5}      {5}             {5}

8.  {6, 7}      {6, 7}          {6}
9.  {6, 7}      {6, 7}          Ambiguo     {}


*/