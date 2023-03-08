#include "Razionale.hh"
#include <iostream>

void test01(){
    using Numerica::Razionale;

    Razionale r;    // costruttore default
    
    Razionale r1(r);    // costruttore di copia
    Razionale r2 = r;   // costruttore di assegnamento 

    Razionale r3 { r };     // costruttore di copia (C++11)
    Razionale r4 { r };     // costruttore di copia (C++11)

    Razionale r5(1, 2);     // costruzione diretta
    Razionale r6 {1, 2};    // costruzione diretta (C++11)
    Razionale r7(1);        // costruzione diretta
    Razionale r8{1};        // costruzione diretta (C++11)
    
    Razionale r9 = 1234;    // costruzione implicita (da evitare!), fa una conversione da int a long e da long a Razionale
    Razionale r10 = true;   // Fa la stessa cosa. Bisogna usare la parola chiave 'explicit' davanti al costruttore

    r = r1;             // assegnamento di copia
    r = Razionale(1);   // assegnamento per spostamento
    r2 = r1 = r;        // concatenazione assegnamenti (evitare?)
    // r2 = (r1 = r) -> r2 = r1

    // Operatori aritmetici binari
    r1 = r + r;
    r1 = r - r;
    r1 = r * r;
    r1 = r / r;

    // Operatori aritmetici unari
    r1 = -r;
    r1 = +r;

    // op-assign
    r += r;
    r -= r;
    r *= r;
    r /= r;

    // Incremento e decremento (pre o post)
    ++r;
    r1 += ++r;

    r++; // evitare?
    --r;
    r--;

    // Operatori relazionari
    bool b;
    b = (r == r);
    b = (r != r);
    b = (r < r);
    b = (r <= r);
    b = (r >= r);
    b = (r > r);

    // Input e output
    std::cin >> r;
    std::cin >> r >> r1;
    std::cout << r << std::endl;

    int n = r.num(); //numeratore
	int d = r.den(); //denominatore
	
	//chiamata esplicita dei distruttori
}

int main(){
    test01();
    return 0;
}