/*
Scrivere l’implementazione dell’algoritmo della STL find_first_of.

L’algoritmo prende in input due sequenze [first1, last1) e [first2, last2), specificate mediante iteratori, ed un predicato
binario comp.

Utilizzando il predicato come operatore di confronto, l’algoritmo cerca nella prima
sequenza il primo elemento “uguale” ad un elemento qualunque della seconda sequenza. Se lo trova,
restituisce l’iteratore corrispondente; altrimenti, restituisce last1.
Si noti che le due sequenze possono avere tipi diversi.

Indicare, motivando la risposta, la più ampia categoria di iteratori utilizzabile per ognuna delle due sequenze di input.

*/

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename IterOne, typename IterTwo, typename Pred>
IterOne find_first_of_(IterOne firstOne, IterOne lastOne, IterTwo firstTwo, IterTwo lastTwo, Pred pred){
    for(; firstOne != lastOne; ++firstOne)
        for(auto i = firstTwo; i != lastTwo; ++i)
            if(pred(*firstOne, *i))
                return firstOne;

    return lastOne;
}

int main(){
    std::list<int> l{1, 2, 3, 4};
    std::vector<char> v{'a', 'b', 'c'};
    auto iter = find_first_of_(l.begin(), l.end(), v.begin(), v.end(), [](int i, char c) -> bool { return (i==11 && c =='c');});
    std::cerr<<*iter<<" -- ";
    
    // test
    auto iter2 = std::find_first_of(l.begin(), l.end(), v.begin(), v.end(), [](int i, char c) -> bool { return (i==11 && c =='c');});
    std::cerr<<*iter2;

    std::cerr<<"\n";
    return 0;
}

/*
Gli iteratori utilizzabili sono degli iteratori che permettono la lettura, il confronto (== e !=) ed il pre/post incremento in entrambe le copie di iteratori.
Quindi i candidati potrebbero essere:
    - iteratori input;
    - iteratori forward;
    - iteratori bidirectional;
    - iteratori random access;

Bisogna fare attenzione però che gli iteratori di input invaliderebbero altri iteratori sulla sequenza, limitando i for ad un solo ciclo ciascuno,
cosa che per il for più esterno va bene, ma per quello interno no.

Quindi si si possono utilizzare:
    - iteratori input;
    - iteratori forward;
    - iteratori bidirectional;
    - iteratori random access;
per il esterno.

Mentre per il for interno si possono usare :
    - iteratori forward;
    - iteratori bidirectional;
    - iteratori random access;

*/