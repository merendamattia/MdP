template <typename Container>
double average1(const Container& v) {
    double sum = 0;
    int counter = 0;
    for(auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
        counter++;
    }
    return sum / counter;
}
/*
Requisiti: 
- Il tipo degli elementi del contenitore deve supportare l'operatore somma e l'operatore divisione.
*/

template <typename Iter>
double average2(Iter begin, Iter end) {
    double sum = 0;
    int counter = 0;
    for(auto it = begin; it != end; ++it) {
        sum += *it;
        counter++;
    }
    return sum / counter;
}

/*
Questa versione è più generale perchè permette di passare due iteratori, che identificano la sequenza su cui calcolare la media, 
e in questo modo possiamo utilizzare anche sequenze non rappresentate da contenitori della libreria standard.
Requisiti:
- Iter begin sia prima di Iter end
- Il tipo Iter supporti l'operatore `++it` e l'operatore `*it`, quindi che sia un Forward Iter, Bidirectional Iter o Random Access Iter.
*/