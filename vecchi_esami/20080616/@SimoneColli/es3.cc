#include <iostream>  
class Animale {  
	public:  
		Animale() { std::cout << "Costruttore Animale" << std::endl; }  
		Animale(const Animale&) { std::cout << "Copia Animale" << std::endl; } 
		
		virtual Animale* clone() const  = 0;

		virtual void verso() const = 0;
		virtual ~Animale() { std::cout << "Distruttore Animale" << std::endl; }  
};

class Cane : public Animale {  
	public:  
		Cane() { std::cout << "Costruttore Cane" << std::endl; }  
		// Cane(const Cane&) { std::cout << "Copia Animale" << std::endl; } 
		
		void verso() const override{ std::cout << "bau!" << std::endl; }

		~Cane() { std::cout << "Distruttore Cane" << std::endl; }  
		Cane* clone() const override { return new Cane(*this); }  
};  
class Pesce : public Animale {  
	public:  
		Pesce() { std::cout << "Costruttore Pesce" << std::endl; }  
		
		void verso() const override { std::cout << "(glu glu)" << std::endl; }  
		~Pesce() override { std::cout << "Distruttore Pesce" << std::endl; }

		Pesce* clone() const override { return new Pesce(*this); }  
};  
class Pescecane : public Pesce {  
	public:  
		Pescecane() { std::cout << "Costruttore Pescecane" << std::endl; }  
		void verso() const override{ std::cout << "(glubau!)" << std::endl; }
		
		~Pescecane() { std::cout << "Distruttore Pescecane" << std::endl; }  
};

int main() {  
	// Animale a;  
	// a.verso();  
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
