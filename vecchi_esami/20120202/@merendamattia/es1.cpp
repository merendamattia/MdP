#include <iostream>

class Base {
public:
    void f(int, double) 
        { std::cout << "Funzione #1" << std::endl; } 
    void f(double, int) const 
        { std::cout << "Funzione #2" << std::endl; }    
    void g(double) const        
        { std::cout << "Funzione #3" << std::endl; }              
    void print(std::ostream&) const
        { std::cout << "Funzione #4" << std::endl; }      
};

class Derived : public Base {
public:
    using Base::f;
    void f(double, double)
        { std::cout << "Funzione #5" << std::endl; }  
    void g(double) const
        { std::cout << "Funzione #6" << std::endl; }                 
public:
    void print(std::ostream&) const
        { std::cout << "Funzione #7" << std::endl; } 
};

int main() {
    Base b;
    Derived d;
    Base* pb = &d;
    const Derived* pd = &d;
    
    std::cout << "Chiamata (a): ";
    pb->print(std::cerr);           // chiamata (a)
    
    std::cout << "Chiamata (b): ";
    pd->print(std::cout);           // chiamata (b)
    
    std::cout << "Chiamata (c): ";
    b.f('a', 0.7);                  // chiamata (c)

    std::cout << "Chiamata (d): ";
    d.f(12.5, 1.4);                 // chiamata (d)

    // std::cout << "Chiamata (e): ";
    // pb->f(2, 0);                    // chiamata (e)

    std::cout << "Chiamata (f): ";
    pd->f(7.2, 7);                  // chiamata (f)

    const Base* pb2 = static_cast<const Base*>(pd);
    std::cout << "Chiamata (g): ";
    pb2->g(0.0);                    // chiamata (g)

    std::cout << "Chiamata (h): ";
    pd->g(0.0);                     // chiamata (h)
}

/*

a) CAND:4       UTIL:4      BEST:4
b) CAND:7       UTIL:none   BEST:none (errore: la funzione non è const ed è privata)
c) CAND:1,2     UTIL:1,2    BEST:1
d) CAND:1,2,5   UTIL:1,2,5  BEST:5
e) CAND:1,2     UTIL:1,2    BEST:1,2 (errore: ambiguo)
f) CAND:1,2,5   UTIL:1,2,5  BEST:2
g) CAND:3       UTIL:none   BEST:none (errore: la funzione non è const)
h) CAND:6       UTIL:6      BEST:6

*/