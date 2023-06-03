#include <iostream>
class Base {
    public:
        void f(int, double){std::cerr<<"1\n";}; // funzione #1
        void f(double, int) const{std::cerr<<"2\n";}; // funzione #2
        void g(double){std::cerr<<"3\n";}; // funzione #3
        void print(std::ostream&) const{std::cerr<<"4\n";}; // funzione #4
};

class Derived : public Base {
    public:
        using Base::f;
        void f(double, double){std::cerr<<"5\n";}; // funzione #5
        void g(double) const{std::cerr<<"6\n";}; // funzione #6
    private:
        void print(std::ostream&){std::cerr<<"7\n";}; // funzione #7
};



int main() {
    Base b;
    Derived d;
    Base* pb = &d;
    const Derived* pd = &d;

    b.print(std::cout); // chiamata (a)
    // d.print(std::cerr); // chiamata (b)
    pb->print(std::cerr); // chiamata (c)
    // pd->print(std::cout); // chiamata (d)
    

    b.f('a', 0.7); // chiamata (e)
    d.f(12.5, 1.4); // chiamata (f)
    // pb->f(2, 0); // chiamata (g)
    pd->f(7.2, 7); // chiamata (h)
    pd->f(7, 7.2); // chiamata (i)
    
    const Base* pb2 = static_cast<const Base*>(pd);

    // pb2->g(0.0); // chiamata (j)
    pd->g(0.0); // chiamata (k)
    return 0;
}

/*

    a. c:{4} u:{4} m:{4}
    b. c:{7} u:{} m:{} ok
    c. c:{4} u:{4} m:{4}
    d. c:{7} u:{} m:{} ok
    e. c:{1, 2} u:{1} m:{1}
    f. c:{1, 2, 5} u:{1, 2, 5} m:{5}
    g. c:{1, 2} u:{1, 2} m:{ambiguo} ok
    h. c:{1, 2, 5} u:{2} m:{2}
    i. c:{1, 2, 5} u:{1} m:{1} -> c:{1, 2, 5} u:{2} m:{2} perché chiama 2? chiama 2 perché pd è costante e 2 è marcata const
    j. c:{3} u:{} m:{} ok
    k. c:{6} u:{6} m:{6}

*/