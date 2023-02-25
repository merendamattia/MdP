# Scope (campo d'azione)

Ogni dichiarazione presente in una unità di traduzione introduce un nome per una entità.

Tale nome può essere utilizzato solo in alcuni punti dell'unità di traduzione: le porzioni di codice in cui il nome è "visibile" sono dette essere il campo di azione (in inglese, scope) per quel nome.

L'ampiezza dello scope per un nome varia a seconda della tipologia
di dichiarazione e del contesto in cui questa appare.

Si distinguono pertanto diverse tipologie di scope:

1. [Scope di namespace](#scope-di-namespace-incluso-lo-scope-globale)
2. [Scope di blocco](#scope-di-blocco)
3. [Scope di classe](#scope-di-classe)
4. [Scope di funzione](#scope-di-funzione)
5. [Scope delle costanti di enumerazione](#scope-delle-costanti-di-enumerazione-un-caso-speciale)

## Scope di namespace (incluso lo scope globale)
Una dichiarazione che non è racchiusa all'interno di una `struct` /`class` e/o all'interno di una funzione ha scope di `namespace`; si noti che lo scope globale è anche esso uno scope di `namespace` (al quale ci si può riferire usando il qualificatore di scope `::`). 

Il nome è visibile, all'interno di quel `namespace`, a partire dal punto di dichiarazione e fino al termine dell'unità di traduzione (in particolare, NON è visibile prima del punto di dichiarazione.

In sostanza, questo è il motivo per il quale le inclusioni degli header file sono collocate all'inizio dei file sorgente).

```c++
namespace N {

    void foo() {
        // ERRORI: bar e a non sono visibili in questo punto (dichiarate dopo)
        bar(a);
    }

    int a; // definizione di 'a'

    void bar(int n) {
        a += n; 
        // OK: 'a' è visibile in questo punto (dichiarata prima) della funzione 'bar'
    }

} // namespace N
```
  
_[Torna all'indice](#scope-campo-dazione)_

---

## Scope di Blocco
Un nome dichiarato in un blocco (porzione di codice all'interno del corpo di una funzione racchiusa tra parentesi graffe) è locale a quel blocco.  

Anche in questo caso, la visibilità inizia dal punto di dichiarazione e termina alla fine del blocco.

```c++
void foo() {
    // ...
    
    { // inizio blocco
        
        // ... 
        
        // inizio scope di blocco per j 
        int j = expr;
        
        // ...

        std::cout << j;
        
        // ...
    
    } // fine dello scope di blocco per j
}
```

Vi sono alcune regole speciali per i costrutti for, while, if, switch e per i blocchi catch:

```c++
for (int i = 0; i != 10; ++i) {
    // i ha lo scope del blocco for
}
```

```c++
if (T* ptr = foo()) {
    // ptr è visibile qui (e vale ptr != nullptr)
} else {
    // ptr è visibile anche qui (e vale ptr == nullptr)
}
```

```c++
switch (int c = bar()) {
    case 0: 
        break;

    case 1:
        do_something(c); // c è visibile qui
        break;

    case 2:
        do_something_different();
        break;

    default:
        std::cerr << "unexpected value c = " << c;
        break;
}
```

```c++
try {
    int a = 5;
    
    // ...
}
catch (const std::string& s) {
    
    std::cerr << s; // 's' è visibile qui
    
    // ATTENZIONE: 'a' NON è visibile qui
}
```

_[Torna all'indice](#scope-campo-dazione)_

---

## Scope di Classe

Qual è la differenza tra struct e classe?
Che le classi garantiscono l'information hiding (l'utente può gestire metodi e attributi con `public` e `private`), mentre le struct no.  

I membri di una classe (tipi, dati, metodi) sono visibili all'interno della classe indipendentemente dal punto di dichiarazione.

```c++
struct S {
    void foo() {
        bar(a); // OK: 'bar' e 'a' sono visibili anche se dichiarati dopo
    }

    int a;
    void bar(int n) { a += n; }
};
```

### Nota 1 
I membri di una classe posso essere acceduti dall'esterno della classe nei modi seguenti:
```c++
    s.foo();   // usando l'operatore punto, se s ha tipo (riferimento a) S
    ps->foo(); // usando l'operatore freccia, se ps ha tipo puntatore a S
    S::foo;    // usando l'operatore di scope.
```

### Nota 2
I membri di una classe `S` possono essere acceduti anche da classi che sono derivate (anche indirettamente) dalla classe `S` (in quanto sono ereditati dalle classi derivate).


_[Torna all'indice](#scope-campo-dazione)_

---

## Scope di Funzione

Le etichette (label) di destinazione delle istruzioni goto hanno scope di funzione: sono visibili in tutta la funzione che le racchiude, indipendentemente dai blocchi.

```c++
void foo() {
    int i;
    {
        inizio: // visibile anche fuori dal blocco
        
        i = 1;
        while (true) {
            // ...
            if (condizione)
                goto fine; // fine è visibile anche se dichiarata dopo
        }
    }
    
    fine:
    
    if (i > 100)
        goto inizio;
    return i;
}
```

L'uso dei goto e delle etichette è considerato cattivo stile e andrebbe
limitato ai casi (pochissimi) in cui risultano essenziali.

_[Torna all'indice](#scope-campo-dazione)_

---

## Scope delle costanti di enumerazione: un caso speciale.

Le costanti di enumerazione dichiarate secondo lo stile C++ 2003
```c++
enum Colors { red, blue, green };
```
hanno come scope quello del corrispondente tipo enumerazione `Colors` (ovvero, sono visibili "fuori" dalle graffe che le racchiudono).

Questo può causare problemi di conflitto di nomi:
```c++
enum Colori { rosso, blu, verde };
enum Semaforo { verde, giallo, rosso };

void foo() { std::cout << rosso; } // a quale rosso si riferisce?
```

Nel C++ 2011 sono state introdotte le `enum class`, che invece limitano lo scope come le classi, costringendo il programmatore a qualificare il nome e evitando potenziali errori:

```c++
enum class Colori { rosso, blu, verde };
enum class Semaforo { verde, giallo, rosso };

void foo() {
  std::cout << static_cast<int>(Colori::rosso);
}
```

### NOTA
Il cast è necessario perché le `enum class` impediscono anche le conversioni implicite di tipo verso gli interi.


_[Torna all'indice](#scope-campo-dazione)_

---