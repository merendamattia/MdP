# Esercizio 4

> Motivare brevemente l’introduzione delle guardie contro l’inclusione ripetuta dei file di intestazione, enunciando chiaramente la regola del linguaggio che verrebbe violata nel caso di un loro mancato (o scorretto) utilizzo. Scrivere un esempio, minimale ma completo, di codice che non si comporta
correttamente a causa dell’assenza di tali guardie.

L'introduzione delle guardie contro l'inclusione ripetuta serve per evitare una potenziale violazione della ODR (_One Definition Rule_), in riferimento al punto 1: ogni unità di traduzione deve contenere al più una definizione di una data variabile, enumerazione, classe o funzione non inline utilizzata nel programma.

Esempio di violazione:

```cpp
// A.hh
// definizione della struct A
struct A {
    int i;
};
// fine A.hh


// B.hh
#include "A.hh"

struct B {
    double d;
};
// fine B.hh


// C.cpp
#include "A.hh"
#include "B.hh"

int main() {
    // ...
    return 0;
}
// fine C.cpp

```

La prima inclusione di `A.hh` nel file `C.cpp` comporta l'importazione del codice relativo alla definizione di `A`; successivamente viene incluso `B.hh` che a sua volta contiene il codice delle definizione di `A`: si sta dunque ridefinendo nuovamente la struct A in una stessa unità di traduzione.
