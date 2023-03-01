#include <iostream>
#include <limits>

int main(){
    std::cout << "Il mio int più grande è: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Il mio long più grande è: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Il mio long long più grande è: " << std::numeric_limits<long long>::max() << std::endl;
    return 0;
}