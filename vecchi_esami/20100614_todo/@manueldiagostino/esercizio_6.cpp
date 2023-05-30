#include <iostream>
#include <new>

struct C { virtual ~C() {std::cout << "C dtor" << std::endl;} /* ... */ }; // distruttore non virtual

struct D : public C { virtual ~D() {std::cout << "D dtor" << std::endl;} /* ... */ };

void job(const C* pc1, const C* pc2) {}

void foo() {
    C* pc = new D();
    job(pc, new C()); // new C() potrebbe fallire --> memory leak di *pc
    delete pc; // viene restituita al sistema solo la memoria inerente a pc, il
    // contenuto del temporaneo restituito da new C() non è eliminato.
}

// Soluzione RAII
// Utilizzare le risorse attraverso un opportuna classe 'gestore', permette
// l'allocazione e deallocazione automatica della memoria, evitando memory leak
// dovuti ad un uso errato di new e delete; inoltre, il codice è sicuro rispetto alle
// eccezioni in quanto l'eccezione viene propagata e non ci sono memory leaks (gli oggetti 
// handler eventualmente creati sono eliminati tramite il distruttore che a sua volta libera
// la memoria dinamica da lui gestita).
struct C_Handler {
private:
    C* data;
public:
    C* getData() const { return data; }
    C_Handler() : data{new C()} { }
    virtual ~C_Handler() { delete data;}
};

struct D_Handler {
private:
    D* data;
public:
    D* getData() const { return data; }
    D_Handler() : data{new D()} { }
    virtual ~D_Handler() { delete data;}
};

void foo_RAII() {
    D_Handler pc;
    job(pc.getData(), C_Handler{}.getData());
}


// Soluzione try-catch
// Questa soluzione è sicura rispetto alle eccezioni in quanto in ogni
// punto questa è gestita e quindi propagata all'indietro; inoltre non vi sono
// memory leaks visto che l'eventuale fallimento della pc2 = new C() sarebbe gestito dal
// relativo blocco catch liberando la memoria precedente riservata a pc;

void foo_TryCatch() {
    C* pc = new D();
    try {
        C* pc2 = new C();
        // throw std::bad_alloc();
        job(pc, pc2);
        delete pc2;
    } catch (...) {
        std::cerr << "deleting pc" << std::endl;
        delete pc;
        throw;
    }
    delete pc;
}

int main (int argc, char *argv[]) {
    foo_RAII();
    foo_TryCatch();
    return 0;
}
