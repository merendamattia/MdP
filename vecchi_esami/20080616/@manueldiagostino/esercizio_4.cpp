#include <iostream>
#include <vector>

/* Requisiti sui parametri del template: 
 * 1) InputIt: si richiede che l'iteratore in questione supporti
 * le operazioni di dereferenziazione (*it), confronto tramite gli 
 * operatori '!=','==' e il preincremento (++it). Inoltre è importante
 * che l'operazione di incremento non invalidi eventuali iteratori definiti
 * a partire da un valore precedente; questo requisito comporta che non possono
 * essere utilizzati gli 'input_iterator' e gli 'output_iterator' (incremento invalida
 * altri puntatori definiti sulla sequenza).
 *
 * 2) Pred: predicato binario che restituisce un valore convertibile al tipo 'bool';
 * in particolare Pred(a,b) restituisce 'true' se a è in relazione con b. 
 *
 * Requisiti sui parametri formali:
 * 1) begin ed end devono appartenere alla stessa sequenza
 * 2) begin <= end
 * 3) i valori puntati da begin,end devono essere compatibili con gli argomenti del
 * predicato 'pred'
 * */



template <typename InputIt, typename Pred>
InputIt
max_element(InputIt begin, InputIt end, Pred pred) {
    if (begin == end)
        return end;

    auto currMaxIt = begin;
    while (++begin != end)
        if (pred(*currMaxIt, *begin))
            currMaxIt = begin; 

    return currMaxIt;
}

int main (int argc, char *argv[]) {
    std::vector<int> v{0,0,0,0,8,0,0,0};
    auto res = max_element(v.begin(), v.end(), std::less<int>{} );
    
    if (res != v.end())
        std::cout << *res << std::endl;
    else
        std::cout << "res null" << std::endl;


    std::vector<std::string> v2{"a", "aa", "abb", "zza"};
    auto res2 = max_element(v2.begin(), v2.end(), std::less<std::string>{} );
    
    if (res2 != v2.end())
        std::cout << *res2 << std::endl;
    else
        std::cout << "res2 null" << std::endl;

    return 0;
}
