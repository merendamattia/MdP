/* 
* Obiettivo: 
*	- definire la classe Unique che implementa gli unique_ptr 
* 	dello standard c++11.
*	- seguire protocollo RAII
* 
*/

#ifndef UNIQUE_HH
#define UNIQUE_HH

#include <cassert>
#include <iostream>

template<typename T>
class Unique_ptr {
public:
	using value_type = T;
	using pointer = value_type*;
	
private:
	pointer data_;

public:
	Unique_ptr() noexcept;
	explicit Unique_ptr(pointer&) noexcept;
	explicit Unique_ptr(pointer&&) noexcept; // rvalue a quel puntatore in quanto non possono esserci altri proprietari
	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr(Unique_ptr&&) = delete;

	Unique_ptr& operator=(const Unique_ptr&) = delete;
	Unique_ptr& operator=(Unique_ptr&&) noexcept;
	~Unique_ptr() noexcept;

	// Functions
	operator bool() const noexcept;
};


// ! IMPLEMENTATION

/*
*	NOTA: la definizione dei metodi di classi templatiche fatta
* 	all'esterno di essa, viene considerata automaticamente come inline
* 	(non c'è violazione della ODR).
*/

template<typename T>
Unique_ptr<T>::Unique_ptr() noexcept :
	data_{nullptr} {
	
	#ifdef DEBUG
	std::cout << "Unique_ptr(): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T>::Unique_ptr(pointer& p) noexcept :
	data_{p} {
	
	p = nullptr;

	#ifdef DEBUG
	std::cout << "Unique_ptr(pointer& p): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T>::Unique_ptr(pointer&& p) noexcept :
	data_{p} {
	
	p = nullptr;

	#ifdef DEBUG
	std::cout << "Unique_ptr(pointer&& p): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T>&
Unique_ptr<T>::operator=(Unique_ptr&& other) noexcept {
	delete data_;
	data_ = other.data_;
	other.data_ = nullptr;

	#ifdef DEBUG
	std::cout << "operator=(Unique_ptr&& other): Oggetto assegnato per spostamento" << std::endl;
	#endif

	return *this;
}

template<typename T>
Unique_ptr<T>::~Unique_ptr() noexcept {
	delete data_;
	data_ = nullptr;

	#ifdef DEBUG
	std::cout << "Oggetto eliminato" << std::endl;
	#endif // DEBUG
}

template<typename T>
Unique_ptr<T>::operator bool() const noexcept {
	return data_ != nullptr;
}

#endif //! UNIQUE_HH
