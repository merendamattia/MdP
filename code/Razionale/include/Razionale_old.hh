#ifndef NUMERICA_RAZIONALE_HH_INCLUDE_GUARD
#define NUMERICA_RAZIONALE_HH_INCLUDE_GUARD 1

namespace Numerica {
    class Razionale { 
        public:
            using Intero = long; // Filosofia "declare one"

        private:        
            Intero num_;
            Intero den_;
            // Razionale(); // Corrisponde a "Razionale() = delete;" nelle versioni precedenti al C++11

            void semplifica();

        public: 
            // Nel dubbio vanno messi sempre tutti
            
            // Mi sta bene l'implementazione di default che fornisce il compilatore, nella maggior parte dei casi non conviene usarlo
            // Razionale() = default; 
            // Razionale(const Razionale&) = default;
            // Razionale(Razionale&&) = default;
            // Razionale& operator=(const Razionale&) = default;
            // Razionale& operator=(Razionale&&) = default;
            // ~Razionale() = default;

            bool check_inv() const;
            Razionale(Intero n, Intero d) : num_(n), den_(d) { // in questo modo inizializzo subito, invece di inizializzare una cosa a caso per poi assegnargli il valore passato (esempio delle villette delle due famiglie)
                // invariante di classe ?

                if(!ben_formato()) // La scelta di implementazione la si lascia al "cliente"
                    throw Razionale_Invalido();
            }
            // Razionale();
            // Razionale() = delete; // Non voglio il costruttore di default (da C++11)

            // const Razionale& operator=(const Razionale&); // Permette di non modificare il riferimento ritornato
            // std::cout << (r = r3); // si
            // ++(r = r3); // no

            Razionale(Intero n, Intero d = 1);
            explicit Razionale(Intero n);

            struct Razionale_Invalido { };

            Razionale& operator++();    // Il tipo di ritorno dipende dalla "libertà" che si vuole dare all'utilizzatore della classe
			Razionale operator++(int);  // questo crea una copia, quindi è preferibile non usarlo oppure non renderlo disponibile (Razionale operator++(int) = delete)

            const Intero& num() const;
            const Intero& den() const;

            // pre-condizioni ==> post-condizioni
            // pre-condizioni: this e a2 sono ben formattati, quindi soddisfano l'invariante di classe
            // post-condizioni: this e a2 non devono essere modificati; this, a2 e il ritorno soddisfano l'invariante
            // TODO: da approfondire "contratti narrow"
            Razionale operator+(const Razionale& a2) const {
                // assert(this->check_inv());
                // assert(a2.check_inv());
                // Li posso omettere perche è presente il const

                Razionale res;

                res.num_ = this->num_ * a2.den_ + a2.num_ * this->den_;
                res.den_ = this->den_ * a2.den_;

                semplifica();

                assert(res.check_inv());
                return res;
            }


            Razionale operator-(const Razionale& a2) const;
            Razionale operator*(const Razionale& a2) const;
            Razionale operator/(const Razionale& a2) const;

            Razionale& operator+=(const Razionale& a2);
            Razionale& operator-=(const Razionale& a2);
            Razionale& operator*=(const Razionale& a2);
            Razionale& operator/=(const Razionale& a2);

            bool operator==(const Razionale& a2) const { //invariante di classe: non faccio il controllo semplifica() su a2 perche so gia che è ben formattato
                assert(check_inv() && a2.check_inv());
                return num_ == a2.num_ && den_ == a2.den_;
            }
            bool operator!=(const Razionale& a2) const;
            bool operator<(const Razionale& a2) const;
            bool operator<=(const Razionale& a2) const;
            bool operator>=(const Razionale& a2) const;
            bool operator>(const Razionale& a2) const;

            void print(std::ostream& os) const;
    
    
    }; // class Razionale

    inline std::ostream& operator<<(std::ostream& os, const Razionale& r){
        r.print(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, const Razionale& r);
    // Razionale::Razionale() { }; // vado a violare la ODR perchè ci troviamo nell'header file! 
                                   // Questa funzione deve essere inline!

} // nameapace Numerica

#endif NUMERICA_RAZIONALE_HH_INCLUDE_GUARD