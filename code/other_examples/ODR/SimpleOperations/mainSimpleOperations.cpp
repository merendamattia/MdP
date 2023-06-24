/*
    make compile
*/
#include "SimpleOperations.hh"

#include <iostream>
using std::cout;
using std::endl;

SimpleOperations::SimpleOperation* SO               // Allocation of bytes for the object, returns a pointer to said object
    = new SimpleOperations::SimpleOperation();      // Alternatively, one could write `FunctionPointers::FunctionPointer* SO`
                                                    // but that would lead to undefined behaviors if dereferenced
                                                    // Elements of SO may be accessed using the `->` operator

int main() {
    SO->printDel();
    SO->printWelcome();
    SO->printMex("Shout out to Simpleflips");

    int a=1; float b=0;
    cout << SO->doAdd(a, b) << endl;
    cout << SO->doSub(b, a) << endl;
    cout << SO->doMUl(a, b) << endl;
    cout << SO->doDiv(a, b) << endl;

    SO->printDel();

    delete SO;
}