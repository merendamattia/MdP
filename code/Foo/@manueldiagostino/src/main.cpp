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

	Foo<float> f3; // Explicit instatiation of Foo<double>
	// f2.foo(); //! LINKAGE ERROR: undefined reference to `Foo<float>::foo()'


	return 0;
}