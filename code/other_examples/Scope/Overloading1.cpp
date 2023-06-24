/*
    Questo esempio si basa molto su un esercizio visto nell'esame del 19/06/2023
    g++ -Wall -Wextra Overriding.cpp -o Overriding
*/
#include <iostream>

using namespace std;

inline void printDel() { cout << "----\n"; }

struct Operations {
    Operations() { cout << "Operations::ctor()" << endl; }
    ~Operations() { cout << "Operations::dtor()" << endl; }

    void doSomethingSimple() { throw "Operations::doSomethingSimple()"; }
    virtual void doSomethingComplex() { throw "Operations::doSomethingComplex()"; }
    virtual void doSomethingTaxing() { throw "Operations::doSomethingTaxing()"; }
};

struct ComplexOperations : public Operations {
    ComplexOperations() { cout << "ComplexOperations::ctor()" << endl; }
    ~ComplexOperations() { cout << "ComplexOperations::dtor()" << endl; }

    void doSomethingSimple() { throw "ComplexOperations::doSomethingSimple()"; }
    void doSomethingComplex() { doSomethingSimple(); }
    virtual void doSomethingTaxing() { throw "ComplexOperations::doSomethingTaxing()"; }
};

struct TaxingOperations : public Operations {
    Operations SO; ComplexOperations CO;
    TaxingOperations() { cout << "TaxingOperations::ctor()" << endl; }
    ~TaxingOperations() { cout << "TaxingOperations::dtor()" << endl; }

    void doSomethingSimple() { throw "TaxingOperations::doSomethingSimple()"; }
    void doSomethingComplex() { throw "TaxingOperations::doSomethingComplex()"; }
    void doSomethingTaxing() { throw "TaxingOperations::doSomethingTaxing()"; }
};

int main() {
    Operations* SO = new TaxingOperations;  // Operations::ctor()
                                            // Operations::ctor()
                                            // Operations::ctor()
                                            // ComplexOperations::ctor()
                                            // TaxingOperations::ctor()
    Operations O; ComplexOperations CO;     // Operations::ctor()
                                            // Operations::ctor()
                                            // ComplexOperations::ctor()
    Operations& rO = O; ComplexOperations* ptrCO = &CO;

    printDel();
    try { SO->doSomethingSimple(); } catch(const char* err) { cout << err << endl; }    // Operations::doSomethingSimple()
    try { SO->doSomethingComplex(); } catch(const char* err) { cout << err << endl; }   // TaxingOperations::doSomethingComplex()
    try { SO->doSomethingTaxing(); } catch(const char* err) { cout << err << endl; }    // TaxingOperations::doSomethingTaxing()
    printDel();
    try { ptrCO->doSomethingSimple(); } catch(const char* err) { cout << err << endl; } // ComplexOperations::doSomethingSimple()
    try { rO.doSomethingComplex(); } catch(const char* err) { cout << err << endl; }    // Operations::doSomethingComplex()
    try { ptrCO->doSomethingTaxing(); } catch(const char* err) { cout << err << endl; } // ComplexOperations::doSomethingTaxing()
    printDel();

    delete SO;      // Operations::dtor()
                    // ComplexOperations::dtor()
                    // Operations::dtor()
                    // Operations::dtor()
}