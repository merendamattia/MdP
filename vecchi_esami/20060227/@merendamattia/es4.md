Senza un corretto utilizzo delle guardie negli header file andremo a violare la prima regola della ODR: non ci devono essere più definizioni di variabili, classi, funzioni, ecc in ogni unità di traduzione che forma un programma.
Esempio: supponiamo di avere una classe razionale "Razionale.hh", una classe polinomio "Polinomio.hh" e un algoritmo che effettua dei calcoli "Calcolo.cc".
I file sono definiti come segue:

```cpp
// Siamo in Razionale.hh
class Razionale { /*...*/ }
```

```cpp
// Siamo in Polinomio.hh
#include "Razionale.hh"
class Polinomio { /*...*/ }
```

```cpp
// Siamo in Calcolo.cc
#include "Razionale.hh"
#include "Polinomio.hh"
void test() { /*...*/ }
```

Come è possibile notare, nel programma Calcolo.cc avremo due definizioni della classe Razionale, una includendola nativamente, e un'altra quando includiamo la classe Polinomio, che a sua volta anch'essa la include.
Questa è una violazione della ODR.