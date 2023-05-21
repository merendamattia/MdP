/*
 *  Il progetto originale viola il principio DIP (Dependency Inversion Principle):
 *  il codice utente (alto livello) dipende direttamente dalle singole implementazioni
 *  di BSoft e BWare; in particolare, l'utilizzo delle due librerie non è uniforme.
 *
 * */

// BSoft.hh
class BSoft {
private:
// ...
public:
void s1();
void s2(const BSoft& y, int n);
void s3(int n);
// ...
};


// BSoft_Adapter.hh
//#include "BSoft.hh"

class BSoft_Adapter : private BSoft {
private:
    // ...
public:
    void s1() {
        BSoft::s1();
    }

    void s2(const BSoft_Adapter& y, int n) {
        BSoft::s2(static_cast<const BSoft&>(y), n);
    }

    void s3(int n) {
        BSoft::s3(n);
    }
};

class BWare {
private:
// ...
public:
    void w1();
    void w2_1(const BWare& y);
    void w2_2(int n);
    void w3(int n);
// ... ecc.
};

// BSoft_Adapter.hh
//#include "BWare.hh"

class BWare_Adapter : private BWare {
private:
    // ...
public:
    void w1() {
        BWare::w1();
    }

    void w2(const BWare_Adapter& y, int n) {
        BWare::w2_1(static_cast<const BWare&>(y));
        BWare::w2_2(n);
    }

    void w3(int n) {
        BWare::w3(n);
    }
};


// ************* Codice utente ************* 

// 1)
// #include "BSoft_Adapter"

void f(BSoft_Adapter& x, const BSoft_Adapter& y, int n) {
    // ...
    if (n > 0)
        x.s3(n);
    else {
        x.s1();
        n = 5;
    }
    // ...
    x.s2(y, n);
    // ...
}

// 2)
// #include "BWare_Adapter.hh"

void g(BWare_Adapter& x, const BWare_Adapter& y, int n) {
    // ...
    if (n > 0)
        x.w3(n);
    else {
        x.w1();
        n = 5;
    }
    // ...
    x.w2(y, n);
    // ...
}
