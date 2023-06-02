Elencare le categorie di iteratori utilizzate nella libreria standard, mostrando la gerarchia di ereditarietà dei corrispondenti tag.
Per ogni categoria, identificare un esempio di applicazione per il quale è opportuno utilizzare un iteratore della categoria suddetta, indicando almeno un motivo per il quale l’utilizzo di iteratori di un’altra categoria risulta inadeguato.


Le categorie di iterator utilizzati nella libreria standard sono:
- input
- forward
- bidirectional
- random access
- output

La gerarchia di ereditarietà è:
output -> input -> forward -> bidirectional -> random access

Esempi:
```cpp
void foo(Iter first){
	for(int i = 0; i < 10; i++)
		*first = 10;
		++first;
}
```
L'iteratore di output ha accesso in sola scrittura e fornisce solo le operazioni di incremento e di accesso (in scrittura). 
Un altro iteratore tipo quello di input non garantirebbe lo stesso funzionamento perché ha accesso in sola lettura.



```cpp
#include <iterator>
#include <iostream>

int main(){

	auto iBegin = std::istream_iterator<double>(std::cin);
	auto iEnd = std::istream_iterator<double>();
	for(; iBegin != iEnd; ++iBegin)
		std::cerr<<*iBegin;
		
	return 0;
}
```
L'iteratore di input ha accesso in sola lettura e fornisce le operazioni di confronto `==`, `!=` di incremento pre/post. Importante è il fatto che questo iteratore consuma la sequenza fornita.
Un iteratore forwad potrebbe essere utilizzato lasciando perché rende disponibili le stesse operazioni di un iteratore di input però non garantisce la sola lettura ed il singolo utilizzo di ogni elemento.


```cpp
template <typename Iter, typename Pred>
void foo(Iter first, Iter last, Pred pred){
	for(;first != last; ++first)
		if(pred(first))
			(*first) = 4;
}
```

L'iteratore forward permette di scorrere una sequenza senza invalidare altri iteratori su di essa, e l'accesso in scrittura.
Un iteratore di input non potrebbe fare lo stesso perché permette l'accesso in sola lettura.

```cpp
template <typename Iter, typename Pred>
void foo(Iter first, Iter last){
	for(;first != last; --first)
		pred(*first);
}
```

L'iteratore bidirectional permette di scorrere una sequenza anche all'indietro, con l'operazione di decremento pre/post, un iteratore forward non fornisce questa operazione.

```cpp
template <typename Iter, typename Pred>
void foo(Iter first, Iter last){
	for(;first < last; ++first)
		pred(*first);
}
```
L'iteratore random access permette anche il confronto mediante `<`, `>`, `<=`, `>=`, gli altri iteratori no
