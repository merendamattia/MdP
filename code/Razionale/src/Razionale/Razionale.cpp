#include <iostream>
#include <numeric>
#include <cassert>

#include "../../include/Razionale/Razionale.hh"

namespace Numerica {

	bool Razionale::check_inv() const {
		if(num_ == 0)
            return den_ != 0;
        if(den_ <= 0)
            return false;
        if(std::gcd(num_, den_) != 1)
            return false;
        // qui l'invariante è soddisfatta
        return true;
	}

	void Razionale::semplifica() {
		assert(den_ > 0);
		Intero gcd = std::gcd(num_, den_);
        if (gcd != 1) {
            num_ /= gcd;
            den_ /= gcd;
        }
	}

	Razionale::Razionale() : Razionale(0, 1) {
		assert(check_inv());
	}

	Razionale::Razionale(const Intero& num, const Intero& den) :
		num_{num}, den_{den} {	

		assert(den != 0);

		if (num_ == 0) {
            den_ = 1;
            assert(check_inv());
            return;
        }

		if (den < 0) {
			den_ = -den;
			num_ = -num;
		}

		semplifica();
		assert(check_inv());
	}

	Razionale::Razionale(const Razionale& other) : 
		num_{other.num_}, den_{other.den_} {
		
		assert(other.check_inv() && check_inv());
	}

	const Razionale& Razionale::operator=(const Razionale& other) {
		num_ = other.num_;
		den_ = other.den_;

		assert(other.check_inv() && check_inv());

		return *this;
	}

	Razionale::Razionale(Razionale&& other) : 
		num_{std::move(other.num_)},
		den_{std::move(other.den_)} {

		std::cout << "Costruttore per spostamento: " << *this << std::endl;
		assert(check_inv());
	}

	const Razionale& Razionale::operator=(Razionale&& other) {
		num_ = std::move(other.num_);
		den_ = std::move(other.den_);

		std::cout << "Assegnamento per spostamento:" << *this << std::endl;
		assert(check_inv());
		return *this;
	}

	Razionale& Razionale::operator+=(const Razionale& other) {
		assert(other.check_inv() && check_inv());

		num_ = (this->num_  * other.den_) + (this->den_ * other.num_);
		den_ *= other.den_;

		semplifica();
		assert(check_inv());
		
		return *this;
	}

	Razionale& Razionale::operator-=(const Razionale& other) {
		assert(other.check_inv() && check_inv());

		num_ = (this->num_  * other.den_) - (this->den_ * other.num_);
		den_ *= other.den_;

		semplifica();
		assert(check_inv());

		return *this;
	}

	Razionale& Razionale::operator*=(const Razionale& other) {
		assert(other.check_inv() && check_inv());

		num_ *= other.num_;
		den_ *= other.den_;

		semplifica();
		assert(check_inv());

		return *this;
	}

	Razionale& Razionale::operator/=(const Razionale& other) {
		assert(other.check_inv() && check_inv());
		assert(other.num_ != 0);

		num_ *= other.den_;
		den_ *= other.num_;

		if (this->den_ < 0) {
			this->den_ = -this->den_;
			this->den_ = -this->den_;
		}

		this->semplifica();
		assert(check_inv());

		return *this;
	}

	bool Razionale::operator==(const Razionale& other) const {
		assert(other.check_inv() && check_inv());

		return ( 
			num_ == other.den_ &&
			den_ == other.den_
		);
	}

	bool Razionale::operator!=(const Razionale& other) const {
		assert(other.check_inv() && check_inv());

		return !(*this == other);
	}

	bool Razionale::operator<(const Razionale& other) const {
		assert(other.check_inv() && check_inv());

		return (
			(num_ * other.den_) < 
			(other.num_ * den_)
		);
	}

	bool Razionale::operator<=(const Razionale& other) const {
		assert(other.check_inv() && check_inv());

		return (
			(num_ * other.den_) <= 
			(other.num_ * den_)
		);
	}

	bool Razionale::operator>(const Razionale& other) const {
		assert(other.check_inv() && check_inv());

		return (
			(num_ * other.den_) > 
			(other.num_ * den_)
		);
	}

	bool Razionale::operator>=(const Razionale& other) const {
		assert(other.check_inv() && check_inv());

		return (
			(num_ * other.den_) >=
			(other.num_ * den_)
		);
	}

	Razionale Razionale::operator+() const {
		assert(check_inv());

		Razionale res(*this);

		assert(res.check_inv());
		return res;
	}

	Razionale Razionale::operator-() const {
		assert(check_inv());

		Razionale res(*this);
		res.num_ = -res.num_;

		assert(res.check_inv());
		return res;
	}

	Razionale& Razionale::operator++() {
		assert(check_inv());
		this->num_ += this->den_;
		assert(check_inv());

		return *this;
	}

	Razionale Razionale::operator++(int t) {
		assert(check_inv());
		Razionale res(*this);
		assert(res.check_inv());

		++(*this);

		assert(check_inv());
		return res;
	}

	Razionale& Razionale::operator--() {
		assert(check_inv());
		this->num_ -= this->den_;
		assert(check_inv());

		return *this;
	}

	Razionale Razionale::operator--(int t) {
		assert(check_inv());
		Razionale res(*this);
		assert(res.check_inv());

		--(*this);

		assert(check_inv());
		return res;
	}

	const Razionale::Intero& Razionale::num() const {
		return num_;
	}

	const Razionale::Intero& Razionale::den() const {
		return den_;
	}

	void Razionale::print(std::ostream& os) const {
		assert(check_inv());
		os << num_;

		if (den_ != 1) {
			os << "/" << den_;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Razionale& r) {
		r.print(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Razionale& r) {
		char slash;
		Razionale::Intero num, den;

		is >> num >> slash;

		if (isspace(slash)) {
			r = Razionale(num, 1);
		} else {
			assert(slash == '/');
			is >> den;
			r = Razionale(num, den);
		}
		
		return is;
	}

	Razionale operator+(const Razionale& left, const Razionale& right) {
		Razionale res(left);
		res += right;
		return res;
	}

	Razionale operator-(const Razionale& left, const Razionale& right) {
		Razionale res(left);
		res -= right;
		return res;
	}

	Razionale operator*(const Razionale& left, const Razionale& right) {
		Razionale res(left);
		res *= right;
		return res;
	}

	Razionale operator/(const Razionale& left, const Razionale& right) {
		Razionale res(left);
		res /= right;
		return res;
	}

} //! namespace Numerica