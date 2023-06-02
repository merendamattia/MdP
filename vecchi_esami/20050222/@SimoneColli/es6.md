```cpp
template <typename T>
class Set : public std::list<T> {
	public:
		// Costruisce l’insieme vuoto.
		Set();
		// Costruisce il singoletto che contiene t.
		Set(T t);
		Set(Set y);
		void operator=(Set y);
		virtual ~Set();
		unsigned int size();
		bool is_empty();
		bool contains(Set y);
		T& min();
		void pop_min();
		void insert(T z);
		void union_assign(Set y);
		void intersection_assign(Set y);
		void swap(Set y);
		std::ostream operator<<(std::ostream os);
	private:
		// ...
```

Gli errori riscontrabili sono:
- l'ereditarietà da `std::list<T>` pubblica che mette a disposizione tutti i metodi di `std::list` all'interno della classe set.
- il costruttore può effettuare conversioni implicite
- il costruttore di copia prende un altro set per valore, e non per riferimento costante, copiando un oggetto possibilmente "pesante"
- il costruttore di copia potrebbe chiamarsi ricorsivamente
- operator= prende per valore, e non per riferimento costante, copiando un oggetto possibilmente pesante
- manca la const correctness
- il metodo `T& min()` ritorna la reference ad un valore permettendone la modifica, rompendo l'invariante di classe
- `swap` prende per valore e non riferimento
- `uninion` e `intersection` prendono per valore e non restituiscono un nuovo set
- `operator<<` viola il principio di sorpresa minima
_Soluzione_
```cpp
template <typename T>
class Set<T>{
	private:
		std::list<T> l;
		// ...
	public:
		// Costruisce l’insieme vuoto.
		Set();
		// Costruisce il singoletto che contiene t.
		explicit Set(T t);
		explicit Set(const Set& y);
		Set& operator=(const Set& y);
		virtual ~Set();
		unsigned int size() const;
		bool is_empty() const;
		bool contains(const Set& y) const;
		const T& min();
		void pop_min();
		void insert(T z);
		Set& union_assign(const Set& y) const;
		Set& intersection_assign(const Set& y) const;
		void swap(Set&& y);
		print(std::ostream& os);
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& s){
	s.print(os);
	return os;
}
```