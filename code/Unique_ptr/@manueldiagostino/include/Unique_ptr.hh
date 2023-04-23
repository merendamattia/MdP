/*
 * Created on Sat Apr 22 2023
 * by Di Agostino Manuel
 * <manuel.diagostino@studenti.unipr.it>
 * <https://github.com/manueldiagostino>
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
	explicit Unique_ptr(const pointer&) = delete;
	explicit Unique_ptr(pointer&) noexcept;
	explicit Unique_ptr(pointer&&) noexcept; // rvalue a quel puntatore in quanto non possono esserci altri proprietari
	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr(Unique_ptr&&) noexcept;

	Unique_ptr& operator=(const Unique_ptr&) = delete;
	Unique_ptr& operator=(Unique_ptr&&) noexcept;
	~Unique_ptr() noexcept;

	// Functions
	pointer	release() noexcept;
	void reset(pointer&& = nullptr) noexcept;
	void swap(Unique_ptr&) noexcept;

	const value_type& operator *() const noexcept;
	pointer operator ->() const noexcept;
	operator bool() const noexcept;
	pointer get() const noexcept;
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
	
	assert(data_ == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr(): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T>::Unique_ptr(pointer& p) noexcept :
	data_{p} {

	p = nullptr;

	assert(data_ != nullptr);
	assert(p == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr(pointer& p): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T>::Unique_ptr(pointer&& p) noexcept :
	data_{p} {
	
	p = nullptr;

	assert(data_ != nullptr);
	assert(p == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr(pointer&& p): Oggetto creato" << std::endl;
	#endif
}
template<typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& other) noexcept :
	data_{std::move(other.data_)} {
	
	other.data_ = nullptr;
	
	assert(other.data_ == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr(Unique_ptr&& other): Oggetto creato per spostamento" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T>&
Unique_ptr<T>::operator=(Unique_ptr&& other) noexcept {
	delete data_;
	data_ = std::move(other.data_);
	other.data_ = nullptr;

	assert(other.data_ == nullptr);

	#ifdef DEBUG
	std::cerr << "operator=(Unique_ptr&& other): Oggetto assegnato per spostamento" << std::endl;
	#endif

	return *this;
}

template<typename T>
Unique_ptr<T>::~Unique_ptr() noexcept {
	delete data_;
	data_ = nullptr;

	#ifdef DEBUG
	std::cerr << "Oggetto eliminato" << std::endl;
	#endif // DEBUG
}

template<typename T>
T*
Unique_ptr<T>::release() noexcept {
	pointer temp = data_;
	data_ = nullptr;

	#ifdef DEBUG
	std::cerr << "release(): puntatore rilasciato" << std::endl;
	#endif

	return temp;
}

template<typename T>
void
Unique_ptr<T>::reset(pointer&& other) noexcept {
	delete data_;
	data_ = other;
	
	#ifdef DEBUG
	std::cerr << "reset(): reset del puntatore" << std::endl;
	#endif
}

template<typename T>
void
Unique_ptr<T>::swap(Unique_ptr& other) noexcept {
	Unique_ptr temp = std::move(*this);
	*this = std::move(other);
	other = std::move(temp);

	#ifdef DEBUG
	std::cerr << "swap(): swap tra *this e other" << std::endl;
	#endif
}

/**
 * @brief Provides access to the object owned by `*this`.
 * 
 * If `get() == nullptr` the behavior is undefined. 
 * @return the content handle by the pointer.
 */
template<typename T>
const T&
Unique_ptr<T>::operator *() const noexcept {
	return *data_; 
}

/**
 * @brief Provides access to the object owned by `*this`.
 * @return the pointer to the object handled by `*this`.
 */
template<typename T>
T*
Unique_ptr<T>::operator ->() const noexcept {
	return data_; 
}

template<typename T>
Unique_ptr<T>::operator bool() const noexcept {
	return (data_ != nullptr) ? true : false;
}

template<typename T>
T*
Unique_ptr<T>::get() const noexcept {
	return data_;
}


template<typename T>
class Unique_ptr<T[]> {
public:
	using value_type = T;
	using pointer = value_type*;
private:
	pointer data_;
public:
	Unique_ptr() noexcept;
	explicit Unique_ptr(const pointer&) = delete;
	explicit Unique_ptr(pointer&) noexcept;
	explicit Unique_ptr(pointer&&) noexcept; // rvalue a quel puntatore in quanto non possono esserci altri proprietari
	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr(Unique_ptr&&) noexcept;

	Unique_ptr& operator=(const Unique_ptr&) = delete;
	Unique_ptr& operator=(Unique_ptr&&) noexcept;
	~Unique_ptr() noexcept;

	// Functions
	pointer	release() noexcept;
	void reset(pointer&& = nullptr) noexcept;
	void swap(Unique_ptr&) noexcept;

	value_type& operator *() const noexcept;
	value_type& operator [](size_t) const noexcept;
	pointer operator +(size_t) const noexcept;

	operator bool() const noexcept;
	pointer get() const noexcept;
};

template<typename T>
Unique_ptr<T[]>::Unique_ptr() noexcept :
	data_{nullptr} {
	
	assert(data_ == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr<T[]>(): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T[]>::Unique_ptr(pointer& p) noexcept :
	data_{p} {
	
	p = nullptr;

	assert(data_ != nullptr);
	assert(p == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr<T[]>(pointer& p): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T[]>::Unique_ptr(pointer&& p) noexcept :
	data_{p} {
	
	p = nullptr;

	assert(data_ != nullptr);
	assert(p == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr<T[]>(pointer&& p): Oggetto creato" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T[]>::Unique_ptr(Unique_ptr&& other) noexcept :
	data_{std::move(other.data_)} {
	
	other.data_ = nullptr;
	
	assert(other.data_ == nullptr);

	#ifdef DEBUG
	std::cerr << "Unique_ptr<T[]>(Unique_ptr&& other): Oggetto creato per spostamento" << std::endl;
	#endif
}

template<typename T>
Unique_ptr<T[]>&
Unique_ptr<T[]>::operator=(Unique_ptr&& other) noexcept {
	delete [] data_;
	data_ = std::move(other.data_);
	other.data_ = nullptr;

	assert(other.data_ == nullptr);

	#ifdef DEBUG
	std::cerr << "operator=<T[]>(Unique_ptr&& other): Oggetto assegnato per spostamento" << std::endl;
	#endif

	return *this;
}

template<typename T>
Unique_ptr<T[]>::~Unique_ptr() noexcept {
	delete [] data_;

	#ifdef DEBUG
	std::cerr << "Unique_ptr<T[]>(): Oggetto eliminato" << std::endl;
	#endif
}


template<typename T>
T*
Unique_ptr<T[]>::release() noexcept {
	pointer temp = data_;
	data_ = nullptr;

	#ifdef DEBUG
	std::cerr << "release<T[]>(): puntatore rilasciato" << std::endl;
	#endif

	return temp;
}


template<typename T>
void
Unique_ptr<T[]>::reset(pointer&& other) noexcept {
	delete [] data_;
	data_ = other;
	
	#ifdef DEBUG
	std::cerr << "reset<T[]>(): reset del puntatore" << std::endl;
	#endif
}

template<typename T>
void
Unique_ptr<T[]>::swap(Unique_ptr& other) noexcept {
	Unique_ptr temp = std::move(*this);
	*this = std::move(other);
	other = std::move(temp);

	#ifdef DEBUG
	std::cerr << "swap<T[]>(): swap tra *this e other" << std::endl;
	#endif
}

template<typename T>
T&
Unique_ptr<T[]>::operator *() const noexcept {
	return *data_; 
}

template<typename T>
T&
Unique_ptr<T[]>::operator [](size_t size) const noexcept {
	return *(data_ + size); 
}

template<typename T>
T*
Unique_ptr<T[]>::operator +(size_t size) const noexcept {
	return (data_ + size);
}

template<typename T>
Unique_ptr<T[]>::operator bool() const noexcept {
	return data_ != nullptr;
}

template<typename T>
T*
Unique_ptr<T[]>::get() const noexcept {
	return data_;
}


#endif //! UNIQUE_HH
