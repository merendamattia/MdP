
Prima della definizione dei metodi bisogna stabilire quali funzioni si vogliano rendere disponibili all'utente, per fare ciò si sfruttano dei "test" che fungeranno da linee guida per la scrittura dei metodi.


## testRazionale.cc


```cpp
#include <Razionale.hh>
#include <iostream>

void test01(){

	using Numerica::Razionale;
	
	Razionale r; //costruttore default
	
	Razionale r1(r); //costruttore di copia
	Razionale r2 = r; //costruttore di assegnamento
	
	Razionale r3 {r}; //costruttore di copia c++11
	Razionale r4 = {r}; //costruttore di copia c++11


	Razionale r5(1, 2); //costruzione diretta
	Razionale r6 {1, 2}; //costruzione diretta c++11

	Razionale r7(1); //costruzione diretta
	Razionale r5 {1}; //costruzione diretta c++11
	
	Razionale r9 = 1234; // costruzione implicita... !!!DA EVITARE!!
	/*
	richiesta di una coversione implicita da intero a razionale
	le conversioni impicite rendono il linguaggi piacevole da utilizzare, ma bisogna stare attenti perché si protrebbero avere conversioni non volute (vedi esempio sotto)

	*/

	r = r1; //assegnamento di cpia
	r = Razinale(1); //assegnamento per spostamento
	
	r2 = r1 = r; //concatenazione assegnamenti (evitare?)
	/*
	come funziona?
	partendo da destra assegno a sinistra
	*/
	
	// operatori aritmetici binari
	r1 = r+r;
	r1 = r-r;
	r1 = r*r;
	r1 = r/r;
	
	
	// operatori aritmetici unari, cambiano con gli interi piccoli
	r1 = -r;
	r1 = +r;
	
	//op-assign (operatori con assegnamento)
	r1 += r; //garantisce che il + avviene una volta sola
	r1 -= r;
	r1 *= r;
	r1 /= r;
	
	//incremento e decremento, pre- o -post
	// sono da evitare? quali devo scegliere?
	++r;
	r++;
	r--;
	--r;
	
	++r--; //compila? lo si vuole?


	//confronto
	bool b;
	b = (r1 == r2);
	b = (r1 != r2);
	b = (r1 <= r2);
	b = (r1 >= r2);
	b = (r1 < r2);
	b = (r1 > r2);

	//input - output
	count<<r1;
	count<<r2;
	
	//qual'è il tipo correto di...
	n = r.num(); //numeratore
	d = r.den(); //denominatore
	
	//chiamata esplicita dei distruttori
	
}

int main(){
	test01();
	return 0;
}
/*
compilazione:



da errore perchè non trova Razionale.hh
quindi creo il file
poi dice che manca using namespace Numerica

*/
```


#### Esempio di conversione implicita

```cpp
void foo(int a, bool b);
void bar(){
	foo(3.7, true);
	foo(true, 3.7);
}
```

Alla chiamata `foo(3.7, true)` si presenta una conversione implicita di un float (3.7) ad un intero.
Alla chiamata `foo(true, 3.7)` si presenta una conversione implicita di un booleano ad un intero, e di un float ad un booleano.

Questa cosa potrebbe comportare problemi, come ad esempio la conversione di un booleano ad un razionale:

```cpp
void foo(const Razionale& r);
void bar(){
	foo(true);
}
```

Questo non rispetta il **principio di sorpresa minima** 

<mark style="background: #FF5582A6;">NOTA</mark>

Le linea guida della progettazione semplice è il dover risolvere un problema alla volta, se bisogna risolvere più problemi, gli risolvo indipendentemente e poi li unisco.


Per compilare:
```bash
g++ -Wall -Wextra -o testRazionale.o -c testRazionale.cc
```

In seguito alla compilazione si andranno a riscontrare degli errori che fungeranno da "todo list" per quello che c'è da fare.

Un esempio di primo errore è l'assenza del file `Razionale.hh`


## Razionale.hh

```cpp
#ifndef NUMERICA_RAZIONALE_HH_INCLUDE_GUARD
#define NUMERICA_RAZIONALE_HH_INCLUDE_GUARD

namespace Numerica{

    class Razionale{ 
        public: 
            // Nel dubbio vanno messi sempre tutti
            
            Razionale() = default; // Mi sta bene l'implementazione di default che fornisce il compilatore
            Razionale(const Razionale&) = default;
            Razionale(Razionale&&) = default;
            Razionale& operator=(const Razionale&) = default;
            Razionale& operator=(Razionale&&) = default;
            ~Razionale() = default;

            // Razionale();
            // Razionale() = delete; // Non voglio il costruttore di default (C++11)

            // const Razionale& operator=(const Razionale&); // Permette di non modificare il riferimento ritornato
            // std::cout << (r = r3); // si
            // ++(r = r3); // no


            using Intero = long; //filosofia declare one

            explicit Razionale(Intero n);
            Razionale(Intero n, Intero d);
            
			Razionale& operator++(); //il tipo di ritorno dipende dalla "libertà" che si vuole dare all'utilizzatore della classe
			Razionale operator++(int); // questo crea una copia quindi è preferibile non usarlo oppure non renderlo disponibile(Razionale operator++(int) = delete)
			
		private:
            // Razionale();
			// Corrisponde a "Razionale() = delete;" nelle versioni precedenti al C++11
    
    }; // bisogna mettere il ; al termine del blocco di una classe

// Razionale::Razionale() { }; // vado a violare la ODR perchè ci troviamo nell'header file! 
// Questa funzione deve essere inline!

} // non bisogna mettere il ; al termine del blocco di un namespace

#endif NUMERICA_RAZIONALE_HH_INCLUDE_GUARD
```

NOTA

con C++11 si intende lo standard del 2011 per cambiare lo standard in fase di compilazione si aggiunge il flag ``-std=c++11`