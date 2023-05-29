#include <iostream>

class Base {
public:
    void f(int, double) {std::cout<<"f1"<<std::endl;} // funzione #1
    void f(double, int) const {std::cout<<"f2"<<std::endl;} // funzione #2
    void g(double) {std::cout<<"f3"<<std::endl;} // funzione #3
    void print(std::ostream&) const {std::cout<<"f4"<<std::endl;} // funzione #4
};


class Derived : public Base {
public:
    using Base::f;
    void f(double, double) {std::cout<<"f5"<<std::endl;} // funzione #5
    void g(double) const {std::cout<<"f6"<<std::endl;} // funzione #6
private:
    void print(std::ostream&) {std::cout<<"f7"<<std::endl;} // funzione #7
};


int main() {
    Base b;
    Derived d;
    Base* pb = &d;
    const Derived* pd = &d;
    pb->print(std::cerr);   // chiamata (a)    CAND{4} UTIL{4} MIGL{4}
    pd->print(std::cout);   // chiamata (b)    CAND{7} UTIL{} MIGL{} 
    b.f('a', 0.7);          // chiamata (c)    CAND{1,2} UTIL{1,2} MIGL{1}
    d.f(12.5, 1.4);         // chiamata (d)    CAND{1,2,5} UTIL{1,2,5} MIGL{5} 
    pb->f(2, 0);            // chiamata (e)    CAND{1,2} UTIL{1,2} MIGL{}
    pd->f(7.2, 7);          // chiamata (f)    CAND{1,2,5} UTIL{2} MIGL{2}
    const Base* pb2 = static_cast<const Base*>(pd);
    pb2->g(0.0);            // chiamata (g)    CAND{3} UTIL{} MIGL{}
    pd->g(0.0);             // chiamata (h)    CAND{6} UTIL{6} MIGL{6}
}
