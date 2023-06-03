#include <iostream>
#include <algorithm>
#include <vector>

template <
    typename IterInput,
    typename IterOutput,
    typename Pred >
void
remove_copy_if_(IterInput i_begin, IterInput i_end, IterOutput out, Pred pred) {
    for(auto it = i_begin; it != i_end; ++it){
        if(not pred(*it)) {
            //out.push_back(*it);
            *out = *it;
            // std::cout << *it << std::endl;
            ++out;
        }
    }
}

template <
    typename IterInput,
    typename IterOutput,
    typename Pred >
void
remove_copy_(IterInput i_begin, IterInput i_end, IterOutput out, Pred pred) {
    remove_copy_if_(i_begin, i_end, i_begin, pred);
}

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> out;

    auto pari = [] (int value) {
        return value % 2 == 0;
    };
    
    remove_copy_if_(v.begin(), v.end(), std::back_inserter(out), pari);
    std::cout << "out: ";
    for(auto& it : out)
        std::cout << it << " ";
    std::cout << std::endl;

    remove_copy_(v.begin(), v.end(), v.begin(), pari);
    std::cout << "v: ";
    for(auto& it : v)
        std::cout << it << " ";
    std::cout << std::endl;

    return 0;
}