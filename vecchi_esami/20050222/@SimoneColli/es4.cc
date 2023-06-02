#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
double average(T seq){
    unsigned int size = 0;
    double sum = 0;
    for(auto i = std::begin(seq); i != std::end(seq); ++i){
        sum += *i;
        ++size;
    }
    if(size == 0)
        return 0;
    else
        return sum/size;
}


template <typename Iter>
double average_(Iter first, Iter last){
    unsigned int size = 0;
    double sum = 0;
    for(;first != last; ++first){
        sum += *first;
        ++size;
    }
    if(size == 0)
        return 0;
    else
        return sum/size;
}

int main(){
    std::vector<int> v{1, 3, 8};
    std::cerr<<average(v)<<"\n";
    std::cerr<<average_(v.begin(), v.end())<<"\n";
    return 0;
}


/*
La prima funzione(averange) richiede che il contenitore fornito permetta l'identificazione
dell'iteratore begin e dell'iteratore end.
La seconda funzione(averange_) richiede che gli iteratori forniti:
- appartengano alla stessa sequenza
- first sia minore di last
- siano iteratori che permettono le operazioni di accesso in lettura, incremento e confronto (== e !=)
    è preferibil evitare gli iteratori di input perché invalidano altri iteratori
La seconda versione è più generale perché permette di astrarre meglio il concetto di sequenza
*/