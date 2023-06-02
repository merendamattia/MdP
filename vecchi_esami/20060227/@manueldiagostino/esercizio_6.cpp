/*
 *  Esempio 1)
 *  
 *  {
 *      // costruisco un oggetto di tipo dinamico Derived ma di tipo statico Base
 *      Base* p_b = new Derived;
 *      delete p_b; // memory leak
 *  }
 *  
 *  In questo esempio il memory leak è dovuto al fatto che il distruttore della
 *  classe Base non è marcato virtual e quindi non sarè invocato il distruttore
 *  di Derived ma solo quello di Base (eliminazione parziale dell'oggetto).
 *
 *
 *
 *  Esempio 2)
 *  
 *  {
 *      Derived* d1 = new Derived;
 *      Derived* d2 = new Derived(*d1); // costruttore di copia di default di Derived
 *      delete d1; // il contenuto di d2->pj è ora indefinito
 *  }
 *
 *  Il problema è che si è lasciato implicitamente public il costruttore di copia di default
 *  che implementa la shallow copy.
 * */

#include <iostream>

class Base {
private:
    int* pi;
    // Assegnamento: privato e non implementato.
    Base& operator=(const Base&);
public:
    Base() : pi(new int) {}
    Base(const Base& b) : pi(new int) { *pi = *(b.pi); }
    virtual ~Base() { delete pi; std::cerr << "Base dtor" << std::endl; }
    int foo() { return *pi; }
};


class Derived : public Base {
private:
    int* pj;
    // Assegnamento: privato e non implementato.
    Derived& operator=(const Derived&);
    Derived(const Derived& other);
public:
    Derived() : pj(new int) { }
    ~Derived() { delete pj; std::cerr << "Derived dtor" << std::endl; }
    int foo() { return *pj + Base::foo(); }
};

int main (int argc, char *argv[]) {
    
    Base* p_b = new Derived;
    delete p_b; 

    return 0;
}
