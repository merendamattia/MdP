Gerarchia: 
- Input -> Forward -> Bidirectional -> Random Access
- Output -> Forward -> Bidirectional -> Random Access

1. Input Iterator: è utile per leggere sequenze di caratteri dall'input stream.
```cpp
std::istream_iterator<std::string> i_begin(std::cin);
std::istream_iterator<std::string> i_end;
```
L'operatore `++` può modificare gli iteratori presenti sulla sequenza (sconsigliato l'utilizzo).

2. Output Iterator: è utile per scrivere sequenze di caratteri sull'output stream.
```cpp
std::ostream_iterator<std::string> out(std::cout, "\n");
*out = "Ciao";
```
`*out` permette l'accesso in solo scrittura.

3. Forward Iterator: estendono le funzionalità degli Input Iterator e lo scorrimento della sequenza non invalida eventuali altri iteratori presenti sulla sequenza.
```cpp
std::forward_list<int> list = {1, 2, 3, 4};
for(auto it = list.begin(); it != list.end(); ++it) {
    *it += 5;
    std::cout << *it << std::endl;
}
```

4. Bidirectional Iterator: estendono le funzionalità dei Forward Iterator e in più permettono di scorrere una sequenza anche al contrario utilizzando l'operatore `--it`.
```cpp
std::list<int> list = {1, 2, 3, 4};
for(auto it = list.rbegin(); it != list.rend(); ++it) {
    *it += 2;
    std::cout << *it << std::endl;
}
```

5. Random Access Iterator: estendono le funzionalità dei Bidirect. Iter. e inoltre permettono di accedere ad elementi di una lista in ordine non sequenziale. Dato un intero `n`, è possibile accedere all'n-esimo elemento di una sequenza in questo modo: `it[n]`, dove `it` è l'iteratore che punta all'inizio della sequenza. Sono utilizzati dagli array built-in, vector, ecc. 