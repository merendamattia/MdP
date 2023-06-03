/*
Scrivere l’implementazione dell’algoritmo della STL remove_copy_if, che ha come parametri una 
sequenza di input ed una sequenza di output, specificate mediante iteratori, ed un predicato unario.
L’algoritmo copia nella sequenza di output, mantenendone l’ordine, gli elementi della sequenza di
input che non soddisfano il predicato; l’algoritmo restituisce l’iteratore corrispondente alla fine
della sequenza di output.
Utilizzando l’algoritmo precedente, implementare l’analogo algoritmo remove_if, che invece di scri-
vere su di una sequenza di output modifica direttamente la sequenza di input. Motivare brevemente
quali siano le categorie di iteratori utilizzabili in ognuno dei due algoritmi.
*/

#include <iostream>
#include <vector>
#include <iterator>

template <typename IterIn, typename IterOut, typename Pred>
IterOut remove_copy_if(IterIn first, IterIn last, IterOut out, Pred pred){
    for(; first != last; ++first)
        if(!pred(*first)){
            *out = *first;
            ++out;
        }

    return out;
}
template <typename Iter, typename Sobstitute, typename Pred>
void remove_if(Iter first, Iter last, Pred pred, Sobstitute sob){
    for(; first != last; ++first)
        if(!pred(*first)){
            *first = sob;
        }
}

struct pred{
    bool operator()(int i) const{
        return i%2 == 0;
    }
};

void test01(){
    std::vector<int> v{1, 2, 3, 4};
    for(auto i : v)
        std::cerr<<i<<" ";
    
    std::cerr<<"\n";
    std::vector<int>v2(v.size());

    pred p;
    auto last = remove_copy_if(v.begin(), v.end(), v2.begin(), p);

    for(auto i = v2.begin(); i != last; ++i)
        std::cerr<<*i<<" ";
    
}
void test02(){
    std::vector<int> v{1, 2, 3, 4};
    for(auto i : v)
        std::cerr<<i<<" ";

    std::cerr<<"\n";
    
    remove_if(v.begin(), v.end(), [](int i) -> bool {return i%2 != 0;}, 0);

    for(auto i : v)
        std::cerr<<i<<" ";
}
int main(){
    test01();
    std::cerr<<"\n";
    test02();
    std::cerr<<"\n";
    return 0;
}

/*
Le categorie di iteratori che possono essere utilizzate per l'agoritmo remove_copy_if sono:

    - per IterIn, degli iteratori che permettono lettura, confronto (== e !=) e pre/post incremento
      ovvero iteratori foreward, bidirectional e random access, non gli iteratori di input perché
      invalidano la sequenza
    - per IterOut, degli iteratori che permetto la scrittura e il pre/post incremento,
      ovvero degli iteratori forward, bidirectional, random access e output 

Le categorie di iteratori che possono essere utilizzate per l'agoritmo remove_if sono:

    - per IterIn, degli iteratori che permettono lettura e scrittura, confronto (== e !=) e pre/post incremento
      ovvero iteratori foreward, bidirectional e random access
*/