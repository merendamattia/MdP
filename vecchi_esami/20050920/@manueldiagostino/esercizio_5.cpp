#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
// typedef std::vector<std::string>::const_iterator const_iter;


void f(const vect& v) {     
    // v.begin(), v.end() resituiscono un const std::vector<std::string>::iterator
    // (di conseguenza anche find() restituisce un iteratore qualificato const)
    // mentre iter è uno std::vector<std::string>::iterator.
    /*const_*/iter i = std::find(v.begin(), v.end(), "cioccolato"); 
    iter i_end = std::find(v.begin(), v.end(), "menta");
    while (i != i_end) { // i_end potrebbe essere minore di i: "menta" viene prima di "cioccolato" in v
        std::cout << *i << std::endl;
        ++i;
    }
}
void g(vect& v) {
    iter i = v.begin();
    iter i_end = v.end();
    *i = "cacao"; // i potrebbe essere uguale a v.end() se v è vuoto: undefined behaviour
    v.insert(i, "vaniglia"); // ok 
    while (i != i_end) { // ok
        std::cout << *i << std::endl;
        ++i;
    }
}
