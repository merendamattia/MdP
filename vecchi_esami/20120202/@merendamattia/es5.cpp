#include <string>

class A {
private:
    int* pi;
    std::string str;
    double* pd;

    void ottieni_risorse() {
        if(pi == nullptr && pd == nullptr) {
            pi = new int;
            try {
                pd = new double;
            } catch(...) {
                delete pi;
                throw;
            }
        }
    }

    void rilascio_risorse() {
        try {
            if(pi != nullptr)
                delete pi;
            if(pd != nullptr)
                delete pd;
        } catch(...) {
            if(pd != nullptr)
                delete pd;
        }
    }

public:
    A(const std::string& s) : pi(nullptr), str(s), pd(nullptr) { 
        ottieni_risorse();
    }
    virtual ~A() { 
        rilascio_risorse();
    }
};

/*
Il primo problema può sorgere nel caso in cui l'allocazione di `pi` vada a buon fine, 
mentre l'allocazione di `pd` no: in questo caso avremo un memory leak di `pi`.

Il secondo problema può sorgere nel caso in cui la deallocazione di `pi` non vada a buon fine, 
generando una eccezione non controllata: in questo caso avremo un memory leak di `pd`.

Con questa soluzione fornita avremo una corretta gestione delle risorse.
*/