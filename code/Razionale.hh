#ifndef NUMERICA_RAZIONALE_HH_INCLUDE_GUARD
#define NUMERICA_RAZIONALE_HH_INCLUDE_GUARD 1

namespace Numerica {
    class Razionale { 
        public: 
            // Nel dubbio vanno messi sempre tutti
            Razionale() = default; // Mi sta bene l'implementazione di default che fornisce il compilatore
            Razionale(const Razionale&) = default;
            Razionale(Razionale&&) = default;
            Razionale& operator=(const Razionale&) = default;
            Razionale& operator=(Razionale&&) = default;
            ~Razionale() = default;

            // Razionale();
            // Razionale() = delete; // Non voglio il costruttore di default (da C++11)

            // const Razionale& operator=(const Razionale&); // Permette di non modificare il riferimento ritornato
            // std::cout << (r = r3); // si
            // ++(r = r3); // no

            Razionale& operator++();    // Il tipo di ritorno dipende dalla "libertà" che si vuole dare all'utilizzatore della classe
			Razionale operator++(int);  // questo crea una copia, quindi è preferibile non usarlo oppure non renderlo disponibile (Razionale operator++(int) = delete)

            using Intero = long; // Filosofia "declare one"

            Razionale(Intero n, Intero d = 1);
            explicit Razionale(Intero n);
            
        private:
            // Razionale(); // Corrisponde a "Razionale() = delete;" nelle versioni precedenti al C++11
    
    }; // class Razionale

    // Razionale::Razionale() { }; // vado a violare la ODR perchè ci troviamo nell'header file! 
                                   // Questa funzione deve essere inline!

} // nameapace Numerica

#endif NUMERICA_RAZIONALE_HH_INCLUDE_GUARD