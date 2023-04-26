#ifndef RAZIONALE_HH
#define RAZIONALE_HH

#include <iostream>

namespace Numerica {
	class Razionale {
	public:
		using Intero = long;
	private:
		Intero num_;
		Intero den_;

		struct Razionale_Invalido { };
		bool check_inv() const;
		void semplifica();
	public:
		Razionale();
		explicit Razionale(const Intero& num, const Intero& den=1);
		~Razionale() = default;

		Razionale(const Razionale& other);
		const Razionale& operator=(const Razionale& other);

		Razionale(Razionale&& other);
		const Razionale& operator=(Razionale&& other);


		Razionale& operator+=(const Razionale& other);
		Razionale& operator-=(const Razionale& other);
		Razionale& operator*=(const Razionale& other);
		Razionale& operator/=(const Razionale& other);

		bool operator==(const Razionale& other) const;
        bool operator!=(const Razionale& other) const;
        bool operator<(const Razionale& other) const;
        bool operator<=(const Razionale& other) const;
        bool operator>=(const Razionale& other) const;
        bool operator>(const Razionale& other) const;

		Razionale operator+() const;
		Razionale operator-() const;

		Razionale& operator++(); // prefisso
		Razionale operator++(int); // postfisso
		Razionale& operator--();
		Razionale operator--(int);

		const Intero& num() const;
		const Intero& den() const;

		void print(std::ostream& os) const;
};

Razionale operator+(const Razionale& left, const Razionale& right);
Razionale operator-(const Razionale& left, const Razionale& right);
Razionale operator*(const Razionale& left, const Razionale& right);
Razionale operator/(const Razionale& left, const Razionale& right);

std::ostream& operator<<(std::ostream& os, const Razionale& r);
std::istream& operator>>(std::istream& is, Razionale& r);

} //! namespace Numerica

#endif //! RAZIONALE_HH