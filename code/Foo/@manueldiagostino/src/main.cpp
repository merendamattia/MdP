/*
 * Created on Sun Apr 23 2023
 * by Di Agostino Manuel
 * <manuel.diagostino@studenti.unipr.it>
 * <https://github.com/manueldiagostino>
 */

//! To compile:
//!		g++ -Wall -Wextra -I../include -I../lib/ main.cpp Foo_int.cpp

#include "../include/Foo_types.hh"

int main(int argc, char const *argv[]) {

	Foo<int> f1; // f1 definition
	f1.foo(); // f1.foo() usage

	Foo<char> f2;
	f2.foo();

	Foo<float> f3; // Implicit instatiation of Foo<double>

	//! LINKAGE ERROR: undefined reference to `Foo<float>::foo()'
	//! There is no definition of this memeber function for this 
	//! translation unit at compile time (compiler can only see the 
	//! declaration in Foo.hh).
	// f2.foo(); 
	return 0;
}