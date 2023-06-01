/*
Il codice si può considerare exception safe in quanto soddisfa i tre requisiti dell'exception safe base.
1. Non causa perdite di risorse.
2. È neutrale rispetto le eccezioni.
3. Lascia gli oggetti utilizzati in uno stato consistente.
*/

#ifndef GESTORE_RISORSA_HH
#define GESTORE_RISORSA_HH

// #include "risorsa.hh"

template <typename T>
class gestore_risorsa {
private:
    T* res;
public:
    gestore_risorsa() : res(aquisisci_risorsa());
    ~gestore_risorsa() { rilascia_risorsa(res); };

    // Disabilitiamo le copie
    gestore_risorsa(const T& other) = delete;
    T* operator=(const T& other) = delete;

    gestore_risorsa(T&& other) : res(other.res) {
        other.res = nullptr;
    }
    T& operator=(T&& other) {
        rilascia_risorsa(res);
        res = other.res;
        other.res = nullptr;
        return *this;
    }
    const T* get() const { return res; }
	T* get() { return res; }
};

#endif

template <typename Sched>
void foo(Sched& v, Sched& w, unsigned n) {
    gestore_risorsa<Sched> v_ptr(v);
    gestore_risorsa<Sched> w_ptr(w);

    transmit(v_ptr.get(), w_ptr.get(), n);
}