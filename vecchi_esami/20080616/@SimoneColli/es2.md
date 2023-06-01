```cpp
#include <iostream>  
class Animale {  
	public:  
		Animale() { std::cout << "Costruttore Animale" << std::endl; }  
		Animale(const Animale&) { std::cout << "Copia Animale" << std::endl; }  
		virtual Animale* clone() const {  
			std::cout << "Clonazione non specificata" << std::endl;  
			return new Animale(*this);  
		}  
		virtual void verso() const {  
			std::cout << "Verso non specificato" << std::endl;  
		}  
		virtual ~Animale() { std::cout << "Distruttore Animale" << std::endl; }  
};

class Cane : public Animale {  
	public:  
		Cane() { std::cout << "Costruttore Cane" << std::endl; }  
		void verso() { std::cout << "bau!" << std::endl; }  
		~Cane() { std::cout << "Distruttore Cane" << std::endl; }  
		Cane* clone() const { return new Cane(*this); }  
};  
class Pesce : public Animale {  
	public:  
		Pesce() { std::cout << "Costruttore Pesce" << std::endl; }  
		void verso() const { std::cout << "(glu glu)" << std::endl; }  
		~Pesce() { std::cout << "Distruttore Pesce" << std::endl; }  
		Pesce* clone() const { return new Pesce(*this); }  
};  
class Pescecane : public Pesce {  
	public:  
		Pescecane() { std::cout << "Costruttore Pescecane" << std::endl; }  
		void verso() const { std::cout << "(glubau!)" << std::endl; }  
		~Pescecane() { std::cout << "Distruttore Pescecane" << std::endl; }  
};

int main() {  
	Animale a;  
	a.verso();  
	Cane c;  
	c.verso();  
	std::cout << "=== 1 ===" << std::endl;  
	
	Pescecane p;  
	p.verso();  
	std::cout << "=== 2 ===" << std::endl;  
	Animale* pc = c.clone();  
	Animale* pp = p.clone();  // pesce
	std::cout << "=== 3 ===" << std::endl;  
	pc->verso();  
	pp->verso();  
	std::cout << "=== 4 ===" << std::endl;  
	delete pp;  
	delete pc;  
	std::cout << "=== 5 ===" << std::endl;  
}  
```

_output_
```bash
Costruttore Animale
Verso non specificato

Costruttore Animale
Costruttore Cane
bau!

=== 1 ===

Costruttore Animale
Costruttore Pesce
Costruttore Pescecane
(glubau!)

=== 2 ===
# errore
Copia Animale
Copia Animale
# vengono invocati i costruttori di copia sia per il cane che per il pescecane (pesce), però non essendo presenti i costruttori di copia in cane e in pesce viene chiamato quello della classe base e stampa "Copia Animale" 
=== 3 ===

bau! # errore
# Il tipo statico Animale non coincide con il tipo dinamico Cane, però in Cane non è presente una funzione che vada a fare l'override di verso (manca il const) quindi viene chiamato il verso di animale
(glu glu)

=== 4 ===

Distruttore Pesce
Distruttore Animale

Distruttore Cane
Distruttore Animale

=== 5 ===

Distruttore Pescecane
Distruttore Pesce
Distruttore Animale

Distruttore Cane
Distruttore Animale

Distruttore Animale

```
