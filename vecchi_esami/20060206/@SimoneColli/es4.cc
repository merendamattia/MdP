#include <list>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void f(const list<list<T> >& ll, list<T>& l) {
    for (typename list<list<T> >::const_iterator ll_i = ll.begin(),
        ll_end = ll.end(); ll_i != ll_end; ++ll_i)

        for (typename list<T>::const_iterator i = ll_i->begin(),
            i_end = ll_i->end(); i != i_end; ++i)
        l.push_back(*i);
}
/*
Generalizzare il codice affinché, mantenendo la funzionalità descritta,
possa lavorare non solo con il tipo lista, ma con combinazioni
qualunque dei contenitori sequenziali della STL.
*/

template <typename T, typename C>
void f2(const T& container, C& container2){
    for (auto i = container.begin(); i != container.end(); ++i)
        for (auto j = i->begin(); j != i->end(); ++j)
            container2.push_back(*j);
};
void test01(){
    list<int> l{1, 2, 3};
    list<int> l_bis{4, 5, 6};
    auto ll = {l, l_bis};
    for(auto i:ll)
        for(auto j:i)
            std::cerr<<j<<" ";
    
    list<int> l2;
    f2(ll, l2);

    std::cerr<<"\n";
    for(auto i:l2)
        std::cerr<<i<<" ";

    std::cerr<<"\n";
}

void test01_v(){
    vector<int> l{1, 2, 3};
    vector<int> l_bis{4, 5, 6};
    auto ll = {l, l_bis};
    for(auto i:ll)
        for(auto j:i)
            std::cerr<<j<<" ";
    
    list<int> l2;
    f2(ll, l2);

    std::cerr<<"\n";
    for(auto i:l2)
        std::cerr<<i<<" ";

    std::cerr<<"\n";
}
/*
Generalizzare ulteriormente il codice affinché accetti come argomenti, invece di contenitori
sequenziali della STL, degli iteratori.

Fornire un (semplice) esempio di applicazione della versione con
iteratori che non possa essere codificato utilizzando la versione con contenitori.
*/
template <typename IterIn, typename IterOut>
void f3(IterIn first, IterIn last, IterOut out){
    for (; first != last; ++first)
        for (auto j = first->begin(); j != first->end(); ++j){
            *out = *j;
            ++out;
        }
};


void test02(){
    list<int> l{1, 2, 3};
    list<int> l_bis{4, 5, 6};
    auto ll = {l, l_bis};
    for(auto i:ll)
        for(auto j:i)
            std::cerr<<j<<" ";
    
    vector<int> l2(10);
    int A[10];

    f3(ll.begin(), ll.end(), A);
    // f2(ll, A); ! non funziona con gli array

    std::cerr<<"\n";
    for(auto i:A)
        std::cerr<<i<<" ";

    std::cerr<<"\n";
}
int main(){
    // test01();
    // test01_v();
    test02();
    return 0;
}