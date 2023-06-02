```cpp
template <typename T>
class Container {
	public:
	Container(int size)
		: sz(size), ps(new T[sz]) {
	}
	~Container() {
		delete ps;
	}
	private:
		T* ps;
		unsigned int sz;
};
```

_Errori_
```cpp
void foo(Container c){};
void ml(){
	Container c(10);
}// memory leak delete senza []


int main(){
	foo(3); // conversione implicita non voluta
	Container c(-3); // dimensione negativa
	ml();
	Container c2 = c; // shallow copy
}

```

_Soluzione_
```cpp
template <typename T>
class Container {
	public:
		Container() = delete;
		explicit Container(unsigned int size)
			: sz(size), ps(new T[sz]){
		}
		explicit Container(const Container& c){
			ps = new T[c.sz];
			sz = c.sz;
		}
		Container(Container&& c) = delete; // rimozione costruttore di spostamento
		Container& operator=(Container&& c) = delete; // rimozione assegnamento per spostamento
		Container& operator=(const Container& c){
			T* new_ps = new T[c.sz];
			try{
				// copia tutti gli elementi
			}
			catch(...){
				delete[] new_ps;
				throw;
			}
			if(ps != nullptr)
				delete[] ps;
			ps = new_ps;
			sz = c.sz;
		}
		~Container() {
			if(ps != nullptr)
				delete[] ps;
		}
	private:
		T* ps;
		unsigned int sz;
};
```

La soluzione proposta è corretta in caso di eccezioni, perché:
- se si verificasse un eccezione durante la fase di creazione del container mediante i costruttori, per la mancanza di memoria per l'allocazione della memoria per l'array verrebbe lanciata un eccezione e non esisterebbe nessun oggetto.
- se si verificasse un eccezione con il costruttore di copia durante l'allocazione/copia del array di c lo stato di this rimarrebbe consistente e non si avrebbero memory leak
