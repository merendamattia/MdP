
class Base {
    private:
        int* pi;
        // Assegnamento: privato e non implementato.
        Base& operator=(const Base&);
    public:
        Base() : pi(new int) {}
        Base(const Base& b) : pi(new int) { *pi = *(b.pi); }
        ~Base() { delete pi; }
        int foo() { return *pi; }
};

class Derived : public Base {
    private:
        int* pj;
        // Assegnamento: privato e non implementato.
        Derived& operator=(const Derived&);
    public:
        Derived() : pj(new int) {}
        ~Derived() { delete pj; }
        int foo() { return *pj + Base::foo(); }
};

int main(){

    // maca il cotruttore di copia a Derived -> lo eredita da Base
    // ma provaca una double free su pj perchè il costruttore di copia fornito
    // dal compilatore effettua una shallow copy e alla distruzione dell'oggetto
    // creato mediante il costruttore di copia dealloca la memoria di pj dell'oggetto
    // originario

    Derived d1;
    Derived d2(d1);
    // Soluzione da aggiungere nei metodi public di Derived
    // Derived(const Derived& b) : pj(new int) { *pj = *(b.pj); }
    
    // errore 2?
    return 0;
}