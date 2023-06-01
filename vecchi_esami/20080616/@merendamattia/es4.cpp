#include <iostream>
#include <vector>

template <typename Iter, typename Pred>
Iter
max_element_(const Iter begin, Iter end, Pred pred) {
    if(begin == end) {
        std::cerr << "Sequenza vuota" << std::endl;
        return end;
    }
    
    auto max = begin;

    for(auto it = begin; it != end; ++it) {
        if(it != begin) {
            if(pred(*max, *it))
                max = it;
        }
    }
    
    return max;
}

int main() {
    using value_type = int;
    using array = std::vector<value_type>;

    auto Greater = [](  const value_type& max, 
                        const value_type& other) {
        if(other > max)
            return true;
        return false;
    };

    array v = {1, 54, 2, 3, 4, 6, 10, 19};

    auto max = max_element_(v.begin(), v.end(), Greater);
    
    if(max != v.end())
        std::cout << *max << std::endl;
    
    return 0;
}

/*
Non possiamo utilizzare iteratori di output in quanto non è permesso utilizzare l'operatore `!=`.
Abbiamo bisogno di iteratori che supportano questo operatore.
*/