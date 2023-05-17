#include <iterator>
#include <vector>

/*
 *  Requisiti minimi sugli argomenti del template:
 *      - Iter: un iteratore compatibile con il comportamento degli input_iterator (
 *        accesso in lettura e operator++() )
 *      - Pred: un callable unario che ritorni qualcosa compatibile con il tipo bool e che
 *        prenda un argomento compatibile con il tipo puntato da iterator
 *
 *  Requisiti minimi sui parametri formali:
 *      - first, last appartengono alla stessa sequenza
 *      - first <= last
 *        */


template <typename Iter,typename Pred>
bool
all_of(Iter first, Iter last, Pred pred) {
    for ( ; first != last; ++first) {
        if (not pred(*first))
            return false;
    }

    return true;
}

// Definisco un callable
bool is_negative(int i) { return i<0; }

// Definisco un oggetto funzione esplicito
struct IsNegative {
    bool operator()(int i) const { return i<0; }
};

bool all_negative(std::vector<int>& vi) {
    return all_of(vi.begin(), vi.end(), [](int i) { return i<0; });

    // return all_of(vi.begin(), vi.end(), IsNegative);
    // return all_of(vi.begin(), vi.end(), is_negative);
}
