// Versione 1
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>


template <typename ContainerFirst, typename ContainerOut>
void
f(const ContainerFirst& ci, ContainerOut& out) {
    using ContainerSecond = typename ContainerFirst::value_type;
    using ContainerSecond_const_iter = typename ContainerSecond::const_iterator;

    for (auto ciFirst_it = ci.begin(), ciFirst_end = ci.end();
            ciFirst_it != ciFirst_end; ++ciFirst_it) {
        
         std::copy(ciFirst_it->begin(), ciFirst_it->end(), std::back_inserter(out));
    }
}

// Versione 2
template <typename IterIn, typename IterOut>
void
f2(IterIn begin, IterIn end, IterOut out) {
    using ContainerSecond_iterator_type = typename std::iterator_traits<IterIn>::iterator_category;
    
    for (; begin != end; ++begin) {
         std::copy(begin->begin(), begin->end(), out);
    }
    
}

int main (int argc, char *argv[]) {
    std::vector<int> v1 {1,2,3};
    std::vector<int> v2 {4,5,6};
    std::vector<std::vector<int>> v_in {v1,v2};
    std::list<int> v_out;

    f(v_in, v_out);
    for (auto& elem : v_out){
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    v_out.clear();

    // esempio semplice
    f2(++(v_in.begin()), v_in.end(), std::back_inserter(v_out));
    for (auto& elem : v_out){
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    return 0;
}
