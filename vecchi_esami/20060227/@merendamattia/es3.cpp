// --------------------------------------------------- Interfacce
// File Fax.hh
class Fax {
private:
    // ...
public:
    virtual void fax_function_1() = 0;
    virtual void fax_function_2(const char*) = 0;
    virtual void fax_function_3(int) = 0;
    virtual ~Fax() { };
};

// File Modem.hh
class Modem {
private:
    // ...
public:
    virtual void modem_function_1(const char*) = 0;
    virtual void modem_function_2() = 0;
    virtual void modem_function_3(unsigned int) = 0;
    virtual ~Modem() { };
};

// --------------------------------------------------- Adattatori
// File FaxAdapter
#include "FaxModem.hh"
#include "Fax.hh"

class FaxAdapter : public Fax {
private: 
    FaxModem_AllStars x;
public:
    void fax_function_1() override { x.fax_function_1(); }
    void fax_function_2(const char* other) override { x.fax_function_2(other); }
    void fax_function_3(int other) override { x.fax_function_3(other); }
    virtual ~FaxAdapter() { };
};

// File ModemAdapter
#include "FaxModem.hh"
#include "Modem.hh"

class ModemAdapter : public Modem {
private: 
    FaxModem_AllStars x;
public:
    void modem_function_1(const char* other) override { x.modem_function_1(other); }
    void modem_function_2() override { x.modem_function_2(); }
    void modem_function_3(unsigned other) override { x.modem_function_3(other); }
    virtual ~ModemAdapter() { };
};

// --------------------------------------------------- Codice utente
// File User.cc
#include "ModemAdapter.hh"
#include "FaxAdapter.hh"

void user_function_1(FaxAdapter& f) {
    f.fax_function_1();
    // ...
    f.fax_function_3(12);
    // ... 
}
void user_function_2(ModemAdapter& m, const char* command) {
    m.modem_function_1(command);
    // ...
    m.modem_function_3(1024);
    // ... 
}

void user_function_3(FaxAdapter& f, ModemAdapter& m) {
    f.fax_function_2("+390521906950");
    // ...
    m.modem_function_2();
    // ... 
}