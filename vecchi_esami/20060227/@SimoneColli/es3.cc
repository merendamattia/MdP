// File FaxModem.hh
class FaxModem_AllStars {
    private:
    // ...
    public:
    void fax_function_1();
    void fax_function_2(const char*);
    void fax_function_3(int);
    // ...
    void modem_function_1(const char*);
    void modem_function_2();
    void modem_function_3(unsigned int);
    // ...
};


// ModemAdapter.hh
// #include "FaxModem_AllStars.hh"
// include guard
class Modem : private FaxModem_AllStars{
    private:
    // ...
    public:
        void modem_function_1(const char* c){
            FaxModem_AllStars::modem_function_1(c);
        }
        void modem_function_2(){
            FaxModem_AllStars::modem_function_2();
        }
        void modem_function_3(unsigned int ui){
            FaxModem_AllStars::modem_function_3(ui);
        }
};

// FaxAdapter.hh
// #include "FaxModem_AllStars.hh"
// include guard
class Fax : private FaxModem_AllStars{
    private:
    // ...
    public:
        void fax_function_1(){
            FaxModem_AllStars::fax_function_1();
        }
        void fax_function_2(const char* c){
            FaxModem_AllStars::fax_function_2(c);
        }
        void fax_function_3(int i){
            FaxModem_AllStars::fax_function_3(i);
        }
};

// codice utente
// include "ModemAdapter.hh" per modem
// include "FaxAdapter.hh" per fax


// precedente
// void user_function_1(FaxModem_AllStars& f) {
//     f.fax_function_1();
//     // ...
//     f.fax_function_3(12);
//     // ...
// }
// void user_function_2(FaxModem_AllStars& m, const char* command) {
//     m.modem_function_1(command);
//     // ...
//     m.modem_function_3(1024);
//     // ...
// }
// void user_function_3(FaxModem_AllStars& f, FaxModem_AllStars& m) {
//     f.fax_function_2("+390521906950");
//     // ...
//     m.modem_function_2();
//     // ...
// }

// nuovo

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