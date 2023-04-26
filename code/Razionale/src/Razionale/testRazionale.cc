#include "../../include/Razionale/Razionale.hh"
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

    Razionale r9 {std::move(r7)}; // costruttore per spostamento
    Razionale r10 = std::move(r5); // assegnamento per spostamento
    
    // Razionale r9 = 1234;    // costruzione implicita (da evitare!), fa una conversione da int a long e da long a Razionale
    // Razionale r10 = true;   // Fa la stessa cosa. Bisogna usare la parola chiave 'explicit' davanti al costruttore

    r = r1;             // assegnamento di copia
    r = Razionale(1);   // assegnamento per spostamento
    r2 = r1 = r;        // concatenazione assegnamenti (evitare?)
    // r2 = (r1 = r) -> r2 = r1

    // Operatori aritmetici binari
    r1 = r + r; // 2
    r1 = r - r; // 0
    r1 = r * r; // 1
    r1 = r / r; // 1

    r2 = Razionale(2) + Razionale(1,2);

    // Operatori aritmetici unari
    r1 = -r;
    r1 = +r;

    // op-assign
    r += r;
    std::cerr << r << std::endl;
    r -= r;
    std::cerr << r << std::endl;
    r *= r;
    std::cerr << r << std::endl;
    r /= Razionale(1);
    std::cerr << r << std::endl;

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
    std::cerr << r << std::endl;
    std::cin >> r >> r1;
    std::cerr << r << ", " << r1 << std::endl;

    std::cout << r << std::endl;
    std::cerr << r << std::endl;


    int n = r.num(); //numeratore
	int d = r.den(); //denominatore
	
	//chiamata esplicita dei distruttori
}

int main(){
    test01();
    return 0;
}