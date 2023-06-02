#include <iostream>
using namespace std;
class Base {
public:
    Base() { cout << "Costruttore Base" << endl; }
    virtual void foo(int) { cout << "Base::foo(int)" << endl; }
    virtual void bar(int) { cout << "Base::bar(int)" << endl; }
    virtual void bar(double) { cout << "Base::bar(double)" << endl; }
    virtual ~Base() { cout << "Distruttore Base" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Costruttore Derived" << endl; }
    void foo(int) { cout << "Derived::foo(int)" << endl; }
    void bar(int) const { cout << "Derived::bar(int)" << endl; }
    void bar(double) const { cout << "Derived::bar(double) const" << endl; }
    ~Derived() { cout << "Distruttore Derived" << endl; }
};

void g(Base b) {
    b.foo(5);
    b.bar(5.5);
}

int main() {
    Derived derived;
    Base base;

    Base& base_ref = base;
    Base* base_ptr = &derived;
    Derived* derived_ptr = &derived;
    
    cout << "=== 1 ===" << endl;
    
    base_ptr->foo(12.0);
    base_ref.foo(7);

    base_ptr->bar(1.0);
    derived_ptr->bar(1.0);
    derived.bar(2);
    
    cout << "=== 2 ===" << endl;
    
    base.bar(1);
    derived.bar(-1.0);

    derived.foo(0.3);
    
    base_ptr->bar('\n');
    
    cout << "=== 3 ===" << endl;
    
    g(*derived_ptr);
    
    return 0;
}

/*
Costruttore Base
Costruttore Derived
Costruttore Base
=== 1 ===
Derived::foo(int)
Base::foo(int)
Base::bar(double)
Derived::bar(double) const 
Derived::bar(int)
=== 2 ===
Base::bar(int)
Derived::bar(double) const
Derived::foo(int)
Base::bar(int)
=== 3 ===
Base::foo(int)
Base::bar(double)
Distruttore Base
Distruttore Derived
Distruttore Base
*/