// Si forniscano il prototipo e l’implementazione della funzione generica count_if, che dati in ingresso
// una sequenza ed un predicato unario, restituisce il numero di elementi di quella sequenza per i quali
// quel predicato `e soddisfatto

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename Range, typename Pred>
unsigned count_if(const Range& r, Pred p) {
    unsigned count = 0;

    for (const auto& elem : r) {
        if (p(elem))
            ++count;
    }

    return count;
}

// Utilizzando la funzione suddetta, scrivere un programma che legge dallo standard input una sequen-
// za di std::string e scrive sullo standard output il numero di stringhe lette aventi una lunghezza
// maggiore di 10.

int main (int argc, char *argv[]) {
    std::istream_iterator<std::string> i_begin{std::cin};
    std::istream_iterator<std::string> i_end{};

    std::vector<std::string> v;
    std::copy(i_begin, i_end, std::back_inserter(v));

    /*
     *  L'unico vincolo è utilizzare la funzione count_if,
     *  quindi utilizzo un predicato che stampa su std::cout le 
     *  stringhe di lunghezza maggiore di 10.
     * */
    unsigned count = count_if(v, [](const std::string& s) {
        if (s.length() <= 10) {
            return false;
        }

        std::cout << s << std::endl;
        return true;
    });

    std::cout << "Ci sono " << count << " stringhe lunghe più di 10 caratteri." << std::endl;

    return 0;
}
