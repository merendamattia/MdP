
Consegna:
Lettura delle stringe nel file e contare quante volte compaiono.

```cpp
#include <map>
#include <string>
#include <iostream>
#inclide <iterator>

using WordFreq = std::map<std::string, unsigned long>;


int main(){
	WordFreq wf;
	
	std::istream_iterator<std::string> i(std::cin);
	std::istream_iterator<std::string> iend;

	for(;i != iene; ++i){
		const auto& s = *i;
		auto iter = wf.find(s);
		if(iter == wf.end()) // se non trovo
			wf.insert(std::make_pair(s, 1));
		else // se trovo
			++iter->second; // oppure ++(*iter).second;
	}
	//for(auto iter = wf.begin(); iter != wf.end(); ++iter)
	for(const auto& p : wf){
		std::cout<<"La stringa "<<p.first<<" occorre numero "<<p.second<<" volte\n";
	}
	return 0;
}



```

> Per indicare la fine dell'inserimento dell'input utilizzo `ctrl+D`


Versione di Stroustrup:

```cpp
#include <map>
#include <string>
#include <iostream>
#inclide <iterator>

using WordFreq = std::map<std::string, unsigned long>;


int main(){
	WordFreq wf;
	
	std::istream_iterator<std::string> i(std::cin);
	std::istream_iterator<std::string> iend;

	for(;i != iend; ++i)
		++wf[*i]; // questo però non è leggibile
		
	for(const auto& p : wf)
		std::cout<<"La stringa "<<p.first<<" occorre numero "<<p.second<<" volte\n";
	
	return 0;
}

```




```cpp
#include <map>
#include <string>
#include <iostream>
#inclide <iterator>

using WordFreq = std::map<std::string, unsigned long>;


// criterio di confronto

struct Greater{
	bool operator()(unsigned long x, unsigned long y) const {
		return x > y;
	}
};

/*
Conta le stringhe di lunghezza n
*/
struct Shorter{
	bool operator()(const std::string& x, const std::string& y) const {
		return x.size() < y.size();
	}
};


using FreqWord = std::multimap<unsigned long, std::string, Greater>; // un alternativa a greater è std::greater<unsigned long>


int main(){
	WordFreq wf;
	
	std::istream_iterator<std::string> i(std::cin);
	std::istream_iterator<std::string> iend;

	for(;i != iend; ++i)
		++wf[*i]; // questo però non è leggibile


	FreqWord fw;
	for(const auto& p : wf){
		fw.insert(std::make_pair(p.second, p.first));
	}
	
	for(const auto& p : fw)
		std::cout<<"La stringa "<<p.first<<" occorre numero "<<p.second<<" volte\n";
	
	return 0;
}

```
