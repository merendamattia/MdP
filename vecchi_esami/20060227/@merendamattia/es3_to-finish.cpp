// File Fax.hh
class Fax {
private:
    // ...
public:
    void fax_function_1();
    void fax_function_2(const char*);
    void fax_function_3(int);
};

// File Modem.hh
class Modem {
private:
    // ...
public:
    void modem_function_1(const char*);
    void modem_function_2();
    void modem_function_3(unsigned int);
};

// File User.cc
#include "Modem.hh"
#include "Fax.hh"

void user_function_1(Fax& f) {
    f.fax_function_1();
    // ...
    f.fax_function_3(12);
    // ... 
}
void user_function_2(Modem& m, const char* command) {
    m.modem_function_1(command);
    // ...
    m.modem_function_3(1024);
    // ... 
}

void user_function_3(Fax& f, Modem& m) {
    f.fax_function_2("+390521906950");
    // ...
    m.modem_function_2();
    // ... 
}