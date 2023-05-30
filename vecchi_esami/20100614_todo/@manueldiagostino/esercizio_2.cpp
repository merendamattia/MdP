#include <iostream>
using namespace std;

struct A {
    virtual void f(int) { cout << "A::f(int)" << endl; }
    virtual void f(double) { cout << "A::f(double)" << endl; }
    virtual void g() { cout << "A::g(double)" << endl; }
    virtual ~A() { cout << "Destructor A::~A()" << endl; }
};

struct B : public A {
    void f(int) { cout << "B::f(int)" << endl; }
    virtual void f(double) const { cout << "B::f(double)" << endl; }
    virtual void g(int) { cout << "B::g(int)" << endl; }
    ~B() { cout << "Destructor B::~B()" << endl; }
};

struct C : public B {
    void f(int) const { cout << "C::f(int)" << endl; }
    void g(int) { cout << "C::g(int)" << endl; }
    ~C() { cout << "Destructor C::~C()" << endl; }
};


int main() {
    A* a = new A;
    B b;
    C c;
    A& ra_b = b;
    B& rb_b = b;
    A& ra_c = c;
    B& rb_c = c;
    cout << "=== 1 ===" << endl;
    ra_b.f(1); // "B::f(int)"
    rb_b.g(1); // "B::g(int)"
    ra_c.f(1); // "B::f(int)"
    rb_c.g(1); // "C::g(int)"
    cout << "=== 2 ===" << endl;
    static_cast<A*>(&b)->f(1.2); // "A::f(double)"
    static_cast<A*>(&c)->f(1); // "B::f(int)"
    static_cast<B*>(&c)->g(1.2); // "C::g(int)"
    cout << "=== 3 ===" << endl;
    b.f(2); // "B::f(int)"
    c.g(3); // "C::g(int)"
    cout << "=== 4 ===" << endl;
    // "Destructor C::~C()"
    // "Destructor B::~B()"
    // "Destructor A::~A()"
    // "Destructor B::~B()"
    // "Destructor A::~A()"
}
