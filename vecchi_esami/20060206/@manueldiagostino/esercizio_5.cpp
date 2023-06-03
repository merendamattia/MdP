#include <iostream>
#include <vector>
#include <forward_list>

/*
 *  Categoria di iteratori più ampia:
 *      - ItFirst: forward_iterator -> necessari operatori ++(), !=(), *() 
 *      e dato un iteratore it1 inizializzato con un iteratore della sequenza 
 *      it di tipo InputIt, allora l'incremento di it non deve invalidare it1. 
 *
 *      - ItSecond: forward_iterator -> necessari operatori ++(), !=(), *(),
 *      in più la seconda sequenza deve essere scorsa più volte.
 * */

template <typename ItFirst, typename ItSecond, typename CompPredicate>
ItFirst
find_first_of(ItFirst first1, ItFirst last1, ItSecond first2, ItSecond last2, CompPredicate comp) {
    for (; first1 != last1; ++first1) {
        ItSecond temp = first2;

        for (; temp != last2; ++temp) {
            if (comp(*first1, *temp))
                return first1;
        }
    }

    return last1;
}

int main (int argc, char *argv[]) {
    std::vector<int> v_first {1,2,3,4,5,6};
    std::forward_list<int> v_second {9,9,5,7};
    
    std::vector<int>::iterator res = find_first_of(
        v_first.begin(), v_first.end(),
        v_second.begin(), v_second.end(),
        std::equal_to<int>{});
   
    if (res != v_first.end())
        std::cout << *res << std::endl;

    return 0;
}
