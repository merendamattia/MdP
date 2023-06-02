#include <iterator>
#include <iostream>

int main(){
    auto iBegin = std::istream_iterator<double>(std::cin);
	auto iEnd = std::istream_iterator<double>();
	for(; iBegin != iEnd; ++iBegin)
		std::cerr<<*iBegin;

    return 0;
}