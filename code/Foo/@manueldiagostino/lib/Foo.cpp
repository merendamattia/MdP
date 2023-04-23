#ifndef FOO_CPP
#define FOO_CPP

#include <iostream>
#include "../lib/Foo.hh"

template<typename T>
void
Foo<T>::foo() {
	std::cerr << "foo() function!" << std::endl;
}

/* 
 * Implementation of the specialized version of the `Foo` class for the `char` type
 */
void Foo<char>::foo() {
	std::cerr << "Specialized foo() function for char!" << std::endl;
}

#endif // ! FOO_CPP