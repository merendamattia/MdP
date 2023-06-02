#include <iostream>
#include <iterator>
#include <vector>

/*
 *  InputIt: un input_iterator
 *  OutputIt: un output_iterator
 *  UnaryPred: soddisfa il concetto di UnaryPredicate e ritorna un valore convertibile a bool
 * */
template <typename InputIt, typename OutputIt, typename UnaryPred>
OutputIt
remove_copy_if(InputIt begin, InputIt end, OutputIt out, UnaryPred p) {
    
    for (; begin != end; ++begin)
        if (not p(*begin))
            *out++ = *begin;

    return out;
}

/*
 *  InputIt: soddisfa i concetti di InputIterator e OutputIterator, ovvero un ForwardIterator
 * */
template <typename InputIt, typename UnaryPred>
void
remove_if(InputIt begin, InputIt end, UnaryPred p) {
    remove_copy_if(begin, end, begin, p);
}


int main (int argc, char *argv[]) {
    std::vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> v2;
    std::ostream_iterator<int> out_it(std::cout, "\n");

    remove_copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](int i) {
        return i<=5;
    });
    
    std::cout << "v2: " << std::endl;
    for (auto& elem : v2)
        std::cout << elem << std::endl;

    std::cout << "v1: " << std::endl;
    for (auto& elem : v1)
        std::cout << elem << std::endl;

    remove_if(v1.begin(), v1.end(), [](int i) {
        return i<=5;
    });

    std::cout << "v1: " << std::endl;
    for (auto& elem : v1)
        std::cout << elem << std::endl;

    return 0;
}
