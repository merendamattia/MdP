#include <vector>

template <typename T>
class A {
    private:
        int i;
        T* p;
        double d;
    public:
        A() : i(), p(new T), d() {}
        ~A() { delete p; };
};

template <typename T>
class B {
    private:
        int i;
        T* p;
        double d;

        B(const B&);
        B& operator=(const B&);
    public:
        B() : i(100), p(new T[i]), d() {}

        ~B() { delete[] p; };
};

class C : private A<std::vector<int> > {
    private:
        B<double> b1;
        B<int> b2;
        C(const C&);

        C& operator=(const C&);

    public:
        C() {}
};

/*
le classi prese in considerazione si comportano correttamente nel caso in cui non si voglia fare un utilizzo del tipo

void user(){
    A<int> a1;
    A<int> a2 = a1;
    A<int> a3(a1);
}

in questo caso verrebbero chiamati costruttore di copia ed di assegnamento forniti dal compilatore
quindi causerebbero una gestione non corretta della memoria
*/
