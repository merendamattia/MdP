/* L'idea è quella di scrivere due interfacce (una per la dunzionalità fax,
 * l'altra per il modem) così da rispettare il principio di separazione delle interfacce
 * (Interface Segregation Principle); il codice utente dovrà essere uniformato a quest'ultime
 * e, nel caso si volesse in futuro modificare il provider di una delle due 
 * funzionalità, basterà modificare il codice sorgente degli adattatori delle interfacce
 * suddette.
 * */




// FaxInterface.hh

#ifndef FAX_INTERFACE_GUARD_HH
#define FAX_INTERFACE_GUARD_HH 

class FaxInterface {
public:
    virtual ~FaxInterface() { }

    virtual void fax_function_1() = 0;
    virtual void fax_function_2(const char*) = 0;
    virtual void fax_function_3() = 0;
private:
    // ...
};

#endif // !FAX_INTERFACE_GUARD_HH



// FaxAdapterAllStar.hh

#ifndef FAX_ADAPTER_ALLSTAR_HH
#define FAX_ADAPTER_ALLSTAR_HH

#include "FaxInterface.hh"
#include "FaxModem.hh" // codice AllStar

class FaxAdapter : public FaxInterface {
private:
    FaxModem_AllStars old_library;
public:
    FaxAdapter() : old_library() { /* ... */ }
    ~FaxAdapter() { /* ... */ }

    void fax_function_1() override {
        old_library.fax_function_1();
    }

    void fax_function_2(const char* m) override {
        old_library.fax_function_2(m);
    }

    void fax_function_3(unsigned int u) override {
        old_library.fax_function_3(u);
    }
};

#endif //! FAX_ADAPTER_ALLSTAR_HH
 




// ModemInterface.hh

#ifndef MODEM_INTERFACE_GUARD_HH
#define MODEM_INTERFACE_GUARD_HH

class ModemInterface {
private: 
    // ...
public:
    virtual ~ModemInterface() { }

    virtual void modem_function_1(const char* m) = 0;
    virtual void modem_function_2() = 0;
    virtual void modem_function_3(unsigned int u) = 0;
};

#endif // !MODEM_INTERFACE_GUARD_HH



// ModemAdapterAllStar.hh

#ifndef MODEM_ADAPTER_ALLSTAR_H
#define MODEM_ADAPTER_ALLSTAR_H

#include "ModemInterface.hh"
#include "FaxModem.hh"

class ModemAdapter : ModemInterface {
private:
    FaxModem_AllStars old_library;
public:
    ModemInterface() : old_library() { }
    ~ModemInterface() { }

    void modem_function_1(const char* m) override {
        old_library.modem_function_1(m); 
    }

    void modem_function_2() override {
        old_library.modem_function_2(); 
    }

    void modem_function_1(unsigned int u) override {
        old_library.modem_function_3(u); 
    }
};

#endif // !MODEM_ADAPTER_ALLSTAR_H






// ************* Codice utente *************

#include "FaxInterface.hh"
#include "ModemInterface.hh"

void user_function_1(FaxInterface& f) {
    f.fax_function_1();
    // ...
    f.fax_function_3(12);
    // ...
}
void user_function_2(ModemInterface& m, const char* command) {
    m.modem_function_1(command);
    // ...
    m.modem_function_3(1024);
    // ...
}
void user_function_3(FaxInterface& f, ModemInterface& m) {
    f.fax_function_2("+390521906950");
    // ...
    m.modem_function_2();
    // ...
}


/*
 *  In questo modo, volendo cambiare provider del servizio modem, basterebbe scrivere una nuova classe
 *  ModemAdapterXX che erediti da ModemInterface e utilizzi nel private un oggetto della nuova
 *  libreria adottata, rimappando i metodi secondo necessità.
 * */
