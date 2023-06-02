/*
Scrivere l’implementazione dell’algoritmo generico della STL max_element, che prende come input
una sequenza ed un criterio di ordinamento (un predicato binario) e restituisce l’iteratore all’elemento
massimo contenuto nella sequenza (comportandosi in modo standard nel caso di sequenza vuota).

Elencare in modo esaustivo i requisiti imposti dall’implementazione sui parametri di tipo e
sugli argomenti della funzione. In particolare, individuare le categorie di iteratori che non possono
essere utilizzate per istanziare il template, motivando la risposta.

*/
#include <vector>
#include <iostream>

template <typename Iter, typename Pred>
Iter max_element(Iter first, Iter last, Pred pred){
    
    auto best = first;
    ++first;

    for(;first < last; ++first)
        if(pred(*first, *best))
            best = first;            
    

    return best;    
}

template <typename Iter, typename Pred>
Iter max_element2(Iter first, Iter last, Pred pred){
    
    if(first == last)
        return first;

    auto best = first;
    ++first;
    
    for(;first != last; ++first)
        if(pred(*first, *best))
            best = first;
        
        
    

    return best;    
}
int main(){

    std::vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(200);
    v.push_back(21);

    auto i = max_element2(v.begin(), v.end(), [](int a, int b)-> bool {return a > b;});
    std::cout<<*i<<"\n";

    return 0;
}
/*
I requisiti imposti sono che:
- il value_type degli iteratori first/last deve essere coerente con quello degli argomenti di pred
- gli iteratori devono essere ad accesso casuale per permettere la comparazione < all'interno di for(;first < last; ++first)

In alternatica con una funzione del tipo

Iter max_element(Iter first, Iter last, Pred pred){
    
    if(first == last)
        return first;

    Iter best = first;
    ++first;
    
    for(;first != last; ++first)
        pred(*best, *first);

    return best;    
}
Questa implementazione richiede che l'iteratore first sia precedente all'iteratore last e che gli iteratori utilizzati supportino le operazioni di:
- comparazione == e !=
- deferenziazione *
- pre/post incremento ++

Ovvero gli iteratori accettati sono quelli:
- input, ma invalida altri iteratori sulla stessa sequenza
- forward
- bidirectional
- random access
*/
