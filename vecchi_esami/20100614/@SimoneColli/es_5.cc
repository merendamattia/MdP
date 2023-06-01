#include <iterator>

template <typename OutIt>
using retType = typename std::iterator_traits<outIt>::value_type;

template <typename FirstIt, typename SecondIt,
            typename OutIt, typename Pred>
void transform(const FirstIt begin){

}