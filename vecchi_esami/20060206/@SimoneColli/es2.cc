#include <iostream>
using namespace std;

class A {
    public:
        A() { cout << "Constructor A::A()" << endl; }
        // A(const A&){cout << "Constructor A::A(A)" << endl;}
        virtual void f(int) { cout << "A::f(int)" << endl; }
        void f(double) { cout << "A::f(double)" << endl; }
        void g(double) { cout << "A::g(double)" << endl; }
        
        virtual ~A() { cout << "Destructor A::~A()" << endl; }
};

class B {
    public:
        B() { cout << "Constructor B::B()" << endl; }
        // B(const B&){cout << "Constructor B::B(B)" << endl;}
        void f(int) { cout << "B::f(int)" << endl; }
        virtual void f(double) { cout << "B::f(double)" << endl; }
        virtual void g(int) { cout << "B::g(int)" << endl; }
        virtual ~B() { cout << "Destructor B::~B()" << endl; }
};


class D : public B, public A {
    public:
        D() { cout << "Constructor D::D()" << endl; }
        // D(const D&) { cout << "Constructor D::D(D)" << endl; }
        void f(int) { cout << "D::f(int)" << endl; }
        using A::g;
        void g(int) { cout << "D::g(int)" << endl; }
        ~D() { cout << "Destructor D::~D()" << endl; }
};

void h(A a, B b, D& d) {
    a.g('a');
    B* pb = &b;
    pb->f(4);
    d.g(44);
}



int main() {
    D d;
    A& ra = d;
    B& rb = d;
    cout << "=== 1 ===" << endl;
    ra.f(1);
    ra.g(1);
    rb.f(1);
    rb.g(1);
    cout << "=== 2 ===" << endl;
    d.f(1.2);
    d.g(1);
    d.g(1.2);
    cout << "=== 3 ===" << endl;
    h(d, d, d);
    cout << "=== 4 ===" << endl;
    return 0;
}

/*
Constructor B::B()
Constructor A::A()
Constructor D::D()

=== 1 ===
D::f(int)
A::g(double)
B::f(int)
D::g(int)

=== 2 ===
D::f(int)
D::g(int)
A::g(double)

=== 3 ===
A::g(double)
B::f(int)
D::g(int)
Destructor B::~B()
Destructor A::~A()
! distruttori sopra non corretti.... perché?
*Destructor A::~A()
*Destructor B::~B()
! secondo me, perché quando viene chiamata la funzione, gli oggetti da creare vengono messi
! su uno stack da sinistra a destra

=== 4 ===
Destructor D::~D()
Destructor A::~A()
Destructor B::~B()

*/