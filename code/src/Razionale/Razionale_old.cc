#include #include "../../include/Razionale/Razionale_old.hh"

#include <numeric>
#include <cassert>

namespace Numerica{
    bool Razionale::check_inv() const {
        if(num_ == 0)
            return den_ == 0;
        if(den_ <= 0)
            return false;
        if(std::gcd(num_, den_) != 1)
            return false;
        // qui l'invariante è soddisfatta
        return true;
    }

    void Razionale::semplifica(){
        assert(den_ > 0);
        Intero gcd = std::gcd(num_, den_);
        if(gcd != 1){
            num_ /= gcd;
            den_ /= gcd;
        }
    }

    Razionale::Razionale(const Intero& num, const Intero& den) : num_(num), den_(den) {
        assert(den != 0);

        if(num_ == 0){
            den_ = 1;
            assert(check_inv()); // controllo invariante
            return;
        }

        if(den < 0){
            num_ = -num_;
            den_ = -den_;
        }

        Intero gcd = std::gcd(num_, den_);
        if(gcd != 1){
            num_ /= gcd;
            den_ /= gcd;
        }
        assert(check_inv()); // controllo invariante
    }


}