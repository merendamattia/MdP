#include <iostream>

void stampa(const char* m) { std::cerr<<m<<std::endl; }


class Base {
public:
    void f(int, double) { stampa("f1"); }
    void f(double, int) const { stampa("f2"); }
    void g(double) { stampa("f3"); }
    void print(std::ostream&) const { stampa("f4"); }
};

class Derived : public Base {
public:
    using Base::f;
    void f(double, double) { stampa("f5"); }
    void g(double) const { stampa("f6"); }
    void print(std::ostream&) { stampa("f7"); }
};

int main() {
    Base b; 
    Derived d;
    Base* pb = &d;
    const Derived* pd = &d;

    b.print(std::cout); // a cand{4} migl{4} util{4}
    d.print(std::cerr); // b cand{7} migl{7} util{7}
    pb->print(std::cerr); // c cand{4} migl{4} util{4}
    //pd->print(std::cout); // d cand{7} util{} migl{} // il metodo Derived::print() non è const

    
    b.f('a', 0.7); // e cand{1,2} util{1,2} migl{1} // una sola conv. standard da char a int + match perfetto secondo arg.
    d.f(12.5, 1.4); // f cand{1,2,5} util{1,2,5} migl{5}
    //pb->f(2, 0); // g cand{1,2} util{1,2} migl{} chiamata ambigua 
    pd->f(7.2, 7); // h cand{1,2,5} util{2} migl{2} // funz. 2 è l'unica const
    pd->f(7, 7.2); // i cand{1,2,5} util{2} migl{2} // come prima
    

    const Base* pb2 = static_cast<const Base*>(pd); // up-cast a Base
    //pb2->g(0.0); // j cand{3} util{} migl{} // Base::g() non const
    pd->g(0.0); // k cand{6} util{6} migl{6}
}
