#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename Iter, typename Pred>
int 
count_if(const Iter& range, Pred pred) {
    int res = 0;
    for(auto it = range.begin(); it != range.end(); ++it) 
        if(pred(*it))
            ++res;
    
    return res;
}

int main(){
    auto lambda = [](const std::string& s) {
        if(s.length() <= 10)
            return false;
        
        std::cout << s << std::endl;
        return true;
    };

    std::istream_iterator<std::string> i_begin{std::cin};
    std::istream_iterator<std::string> i_end{};

    std::vector<std::string> v;
    std::copy(i_begin, i_end, std::back_inserter(v));

    auto res = count_if(v, lambda);
    std::cout << "Res = " << res << std::endl;

    return 0;
}