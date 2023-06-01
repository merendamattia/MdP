#include <string>
#include <iostream>

namespace N {
    class C {
    private:
        std::string& first() // funzione #1
            { std::cout << "Funzione #1 " << std::endl; } 
    
    public:
        const std::string& first() const // funzione #2
            { std::cout << "Funzione #2 " << std::endl; std::string pippo = ""; return pippo;}

        std::string& last() // funzione #3
            { std::cout << "Funzione #3 " << std::endl; std::string pippo = ""; return pippo;}

        const std::string& last() const  // funzione #4
            { std::cout << "Funzione #4 " << std::endl; std::string pippo = ""; return pippo;}
        
        C(const char*) // funzione #5
            { std::cout << "Funzione #5 " << std::endl; }
    }; // class C
    
    void print(const C&) // funzione #6
        { std::cout << "Funzione #6 " << std::endl; }
    std::string& f(int) // funzione #7
        { std::cout << "Funzione #7 " << std::endl; }

} // namespace N

class A {
public:
    explicit A(std::string&) // funzione #8
        { std::cout << "Funzione #8 " << std::endl; }
};

void print(const A&) // funzione #9
    { std::cout << "Funzione #9 " << std::endl; }

void f(N::C& c) { // funzione #10
    std::cout << "Funzione #10 " << std::endl; 
    
    // std::cout << "Chiamata #1: ";
    // const std::string& f1 = c.first();  // chiamata #1

    // std::cout << "Chiamata #2: ";
    // std::string& f2 = c.first(); // chiamata #2

    std::cout << "Chiamata #3: ";
    const std::string& l1 = c.last(); // chiamata #3

    std::cout << "Chiamata #4: ";
    std::string& l2 = c.last(); // chiamata #4
}

void f(const N::C& c) { // funzione #11
    std::cout << "Funzione #11 " << std::endl; 

    std::cout << "Chiamata #5: ";
    const std::string& f1 = c.first();  // chiamata #5

    // std::cout << "Chiamata #6: ";
    // std::string& f2 = c.first(); // chiamata #6

    std::cout << "Chiamata #7: ";
    const std::string& l1 = c.last(); // chiamata #7

    // std::cout << "Chiamata #8: ";
    // std::string& l2 = c.last(); // chiamata #8
}

int main() {
    std::cout << "Chiamata #9: ";
    N::C c("begin");    // chiamata #9

    std::cout << "Chiamata #10: ";
    f(c);               // chiamata #10

    std::cout << "Chiamata #11: ";
    f("middle");        // chiamata #11

    // std::cout << "Chiamata #12: ";
    // print("end");       // chiamata #12
}

/*

01) CAND:1,2    UTIL:2      BEST:none (errore: è un metodo privato)
02) CAND:1      UTIL:1      BEST:none (errore: è un metodo privato)
03) CAND:3,4    UTIL:4      BEST:4
04) CAND:3,4    UTIL:3      BEST:3
05) CAND:2      UTIL:2      BEST:2
06) CAND:none   UTIL:none   BEST:none (errore: f2 deve essere const)
07) CAND:4      UTIL:4      BEST:4
08) CAND:none   UTIL:none   BEST:none (errore: l1 deve essere const)
09) CAND:5      UTIL:5      BEST:5
10) CAND:10,11  UTIL:10     BEST:10
11) CAND:10,11  UTIL:11     BEST:11 (errore: non è presente nessuna funz. util.) ?
12) CAND:9      UTIL:none   BEST:none (errore: non è presente nessuna funz. util.)

*/

/* 
Domande:
1. Perchè "Chiamata #3: Funzione #3" e non "Chiamata #3: Funzione #4" ?
2. Perchè "Chiamata #11: Funzione #5 Funzione #11" ? 
3. Perchè "Chiamata #10: Funzione #10" e non "Chiamata #10: Funzione #11" ?
*/