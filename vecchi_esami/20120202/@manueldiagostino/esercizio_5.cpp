/*
 * Problema 1
 * Nel costruttore di A, nel caso pi(new int) andasse a buon fine e pd(new double) fallisse,
 * ci sarebbe un memory leak relativo al contenuto di pi.
 */


 /*
 * Problema 2
 * Il distruttore non è marcato 'virtual', un oggetto instanziato da una classe derivata
 * da A potrebbe non essere correttamente distrutto, creando memory leak:
 * */

#include <memory>
#include <string>
#include <iostream>
class A {
    int* pi;
    std::string str;
    double* pd;
public:
    A(const std::string& s) : pi(new int), str(s), pd(new double) { }
    ~A() { delete pi; delete pd; std::cout << "A dtor" << std::endl; }
};

class B : public A {
private:
    int* p2i;
public:
    B() : A("ciao"), p2i(new int) { }
    virtual ~B() { delete p2i; std::cout << "A dtor" << std::endl; }
};

// Soluzione: implementa paradigma RAII

class A_corretta {
    std::unique_ptr<int> pi;
    std::string str;
    std::unique_ptr<double> pd;
public:
    A_corretta(const std::string& s) : pi(new int), str(s), pd(new double) { }
    virtual ~A_corretta() { std::cout << "A dtor" << std::endl; }
};


int main (int argc, char *argv[]) {
    A* pa_b = new B;
    delete pa_b; // elimina solo l'oggetto base A di B
    
    return 0;
}
