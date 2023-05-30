#include <iterator>
#include <iostream>
#include <vector>


template <
    typename FirstIt,
    typename SecondIt,
    typename OutputIt,
    typename Pred>
void
transform(
    FirstIt firstBegin,
    FirstIt firstEnd,
    SecondIt secondBegin,
    OutputIt outputBegin,
    Pred pred) {

    while (firstBegin != firstEnd) {
        *outputBegin = pred(*firstBegin, *secondBegin);

        ++firstBegin;
        ++secondBegin;
        ++outputBegin;
    }
}

int main (int argc, char *argv[]) {
   
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = {0,0,0};
    std::ostream_iterator<double> out{std::cout, "\n"};

    transform(v1.begin(), v1.end(), v2.begin(), out, [](int l, int r) {
            return(l + r)/2.0;
        }
    );

    return 0;
}

