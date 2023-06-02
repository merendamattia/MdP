#include <iostream>
#include <algorithm>
#include <vector>

template <
    typename IterInput,
    typename IterOutput,
    typename Pred >
IterOutput& 
remove_copy_if_(IterInput i_begin, IterInput i_end, IterOutput out, Pred pred) {
    for(auto it = i_begin; it != i_end; ++it){
        if(not pred(*it)) {
            *out = *it;
            // std::cout << *it << std::endl;
            ++out;
        }
    }
    return out;
}

int main() {
    std::istream_iterator<int> i_begin(std::cin);
    std::istream_iterator<int> i_end;
    std::vector<int> out;

    auto equals_to_5 = [] (int value) {
        return value == 5;
    };
    
    auto o_end = remove_copy_if_(i_begin, i_end, out, equals_to_5);
    
    for(auto it = out.begin(); it != out.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}