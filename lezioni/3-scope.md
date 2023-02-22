TODO: aggiungi indice, aggiungi 'torna all'indice'
# Scope (campo d'azione)

Ogni dichiarazione presente in una unità di traduzione introduce un nome per una entità.

Tale nome può essere utilizzato solo in alcuni punti dell'unità di traduzione: le porzioni di codice in cui il nome è "visibile" sono dette essere il campo di azione (in inglese, scope) per quel nome.

L'ampiezza dello scope per un nome varia a seconda della tipologia
di dichiarazione e del contesto in cui questa appare.

Si distinguono pertanto diverse tipologie di scope:

1. [Scope di namespace](#scope-di-namespace-incluso-lo-scope-globale)
2. [Scope di blocco](#scope-di-blocco)
3. [Scope di classe](#scope-di-classe)

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

## Scope di blocco
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

## Scope di classe




_[Torna all'indice](#scope-campo-dazione)_

---