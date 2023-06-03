#include <vector>

template <typename T>
class A {
private:
    int i;
    T* p;
    double d;
public:
    // errore: shallow copy di A(const A&) e A& operator=(const A&)
    A() : i(), p(new T), d() {}
    ~A() { delete p; }; // ok, se la costruzione riesce p non è mai nullptr ma non virtual
};

template <typename T>
class B {
private:
    int i;
    T* p;
    double d;
    B(const B&);
    B& operator=(const B&);
    
public:
    B() : i(100), p(new T[i]), d() {}
    ~B() { delete[] p; }; // non virtual
};


class C : private A<std::vector<int> > {
private:
    B<double> b1;
    B<int> b2;
    C(const C&);
    C& operator=(const C&);
public:
    C() {}
};
