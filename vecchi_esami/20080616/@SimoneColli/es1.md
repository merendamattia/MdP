```cpp
#include <string>
namespace N {
    class C {
        private:
        std::string& first(); // funzione #1
        public:
        const std::string& first() const; // funzione #2
        std::string& last(); // funzione #3
        const std::string& last() const; // funzione #4
        C(const char*); // funzione #5
    }; // class C

    void print(const C&); // funzione #6
    std::string& f(int); // funzione #7
} // namespace N

class A {
    public:
        explicit A(std::string&); // funzione #8
};
void print(const A&); // funzione #9

void f(N::C& c) // funzione #10
{
    const std::string& f1 = c.first(); // chiamata #1
    std::string& f2 = c.first(); // chiamata #2
    const std::string& l1 = c.last(); // chiamata #3
    std::string& l2 = c.last(); // chiamata #4
}
void f(const N::C& c) // funzione #11
{
    const std::string& f1 = c.first(); // chiamata #5
    std::string& f2 = c.first(); // chiamata #6
    const std::string& l1 = c.last(); // chiamata #7
    std::string& l2 = c.last(); // chiamata #8
}

int main() {
    N::C c("begin"); // chiamata #9
    f(c); // chiamata #10
    f("middle"); // chiamata #11
    print("end"); // chiamata #12
}
```

| Chiamata | Candidate | Utilizzabili | Migliore  | Note                                                                                                                                                                                          | Correzione |
| -------- | --------- | ------------ | --------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| 1        | 1, 2      | Nessuna      | Nessuna   | `c.first()` invocherebbe la funzione 1, però è privata quindi non può essere utilizzata.Invocherebbe la funzione 2, però c (argomento della funzione) non è costante quindi non può invocarla |            |
| 2        | 1, 2      | Nessuna      | Nessuna   | come la chiamata 1                                                                                                                                                                                 |            |
| 3        | 3, 4      | 3            | 3         | Qui viene chiamata la funzione 3 perché anche se l1 è un riferimento costante ad una stringa, c (argomento della funzione) non lo è, quindi viene invocata la funzione 3                 |            |
| 4        | 3, 4      | 3            | 3         |                                                                                                                                                                                               |            |
| 5        | 1, 2      | 2            | 2         | Qui c (argomento della funzione) è un riferimento costante, quindi è possibile invocare la funzione 2 marcata const                                                                           |            |
| 6        | 1, 2      | Nessuna      | Nessuna   | Il ragionamento è lo stesso della chiamata 5 però viene restituita un riferimento costante a stringa che non può essere convertito in riferimento non costante                                |            |
| 7        | 3, 4      | 4            | 4         |                                                                                                                                                                                               |            |
| 8        | 3, 4      | Nessuna      | Nessuna   | Stesso ragionamento della chiamata 6                                                                                                                                                          |            |
| 9        | 5         | 5            | 5         |                                                                                                                                                                                               |            |
| 10       | 10, 11, 7 | 10, 11       | 10        | Qui viene chiamata la 10 perché la c creata alla chiamata 9 non è costante, quindi viene preferita la funzione senza qualificazione                                                           |            |
| 11       | 10, 11    | 10, 11       | Ambiguità |                                                                                                                                                                                               | Non è presente nessuna funzione utilizzabile perché le candidate aspettano come argomento un oggetto di tipo C            |
| 12       | 9   | Nessuna      | Nessuna   | Perché print fa parte del namespace N                                                                                                                                                         |      Non è presente nessuna funzione utilizzabile perché le candidata aspettana come argomento un oggetto di tipo A      |

