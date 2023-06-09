#include <string>
#include <iostream>

class D;
class C {
private:
    // ...
public:
    C() {}
    C(const D&) {}
    // ...
};
class D {
private:
    // ...
public:
    D() {}
    D(const C&) {}
    // ...
};

inline
void stampa(const char* m) { std::cout << m << std::endl; }

void f(double d) { stampa("f1"); }
void f(int i, C c = C()) { stampa("f2"); }
void f(double d, C c = C()) { stampa("f3"); }
void g(C c, D d) { stampa("f4"); }
void g(D d, C c = C()) { stampa("f5"); }
void h(const char* s) { stampa("f6"); }
void h(const std::string& s) { stampa("f7"); }

int main() {
    C c; 
    D d;

    f('a'); // 1 cand{1,2,3} util{1,2,3} migl{2} // una sola promozione
    f('a', c); // 2 cand{1,2,3} util{2,3} migl{2} // promozione sul primo arg. vince su conv. sta.
    //f(3.2); // 3 cand{1,2,3} util{1,2,3} migl{} // ambigue 1,3
    g(c, d); // 4 cand{4,5} util{4,5} migl{4} // match perfetto vs conv. definita dall'utente
    g(d, c); // 5 cand{4,5} util{4,5} migl{5}
    g(c); // 6 cand{4,5} util{5} migl{5} // conv. c -> d
    g(d); // 7 cand{4,5} util{5} migl{5}
    h("abra"); // 8 cand{6,7} util{6,7} migl{6} // decay array puntatore vs conv. definita utente
    //h('a'); // 9 cand{6,7} util{} migl{} // nessuna conversione
}
