# Prova 2010-06-14

## Esercizio 1
Chiamata A:     cand:1,2    util:1,2    best:1
Chiamata B:     cand:10     util:10     best:10
Chiamata C:     cand:10,5,6 util:6      best:6
Chiamata D:     cand:5,6    util:5      best:5
Chiamata E:     errore
Chiamata F:     cand:7,8    util:7,8    best:8
Chiamata G:     cand:7,8    util:7,8    best:7
Chiamata H:     cand:9,11,12  util:9,12     best:9
Chiamata I:     cand:11,12  util:11     best:11
Chiamata J:     errore

## Esercizio 2
=== 1 ===
B::f(int)
B::g(int)
B::f(int)
C::g(int)
=== 2 ===
A::f(double)
A::f(int)
C::g(int)
=== 3 ===
B::f(int)
C::g(int)
=== 4 ===
Destructor C::~C()
Destructor B::~B()
Destructor A::~A()
Destructor B::~B()
Destructor A::~A()

## Esercizio 4
```cpp
#include <string>
#include <vector>
#include <iostream>

// aggiungo la libreria <algorithm>
#include <algorithm>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
typedef std::vector<std::string>::const_iterator c_iter;

void f(const vect& v) {
    c_iter i = std::find(v.begin(), v.end(), "inizio");
    // Errore: si sta provando ad assegnare un iteratore const ad un iteratore non const
    // Creo un nuovo alias e uso questo typedef std::vector<std::string>::const_iterator c_iter;
    c_iter i_end = std::find(v.begin(), v.end(), "fine");
    while (i < i_end) { // chi mi dice che i viene prima di i_end? Versione corretta i < i_end
        std::cout << *i << std::endl;
        ++i; 
    }
}

void g(vect& v) {
    iter i = v.begin(), i_end = v.end();
    // chi mi dice che i < i_end? Devo fare un controllo
    if(v.isEmpty())
        return;
    v.insert(++i, "prima");
    v.insert(++i, "dopo");
}
```

## Esercizio 5
```cpp
template <typename First, typename Second, typename Pred>
```