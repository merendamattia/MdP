/*
 * Created on Sat Apr 22 2023
 * by Di Agostino Manuel
 * <manuel.diagostino@studenti.unipr.it>
 * <https://github.com/manueldiagostino>
 */


#include "../include/Unique_ptr.hh"
#include <iostream>
#include <memory>

// g++ -D DEBUG -Wall -Wextra -I../include/ test.cpp -o a.out


// Allocation test
void
test_01() {
	std::cerr << "******** TEST 01 ********" << std::endl;
	Unique_ptr<int> u1;

	int* p1 = new int(10);
	std::cerr << "*p1: " << *p1 << std::endl;
	Unique_ptr<int> u3(p1); // Unique_ptr(const pointer&)
	if (!p1)
		std::cerr << "p1 is now nullptr" << std::endl;
	std::cerr << std::endl;


	Unique_ptr<int> u2(new int(1)); // Unique_ptr(pointer&&)

	u1 = std::move(u2); // operator=(Unique_ptr&&)

	int* p2 = new int(9);
	std::cerr << "*p2: " << *p2 << std::endl;
	Unique_ptr<int> u4(std::move(p2));
	if (!p2)
		std::cerr << "p2 is now nullptr" << std::endl;
	std::cerr << std::endl;
}

// Functions test
void
test_02() {
	std::cerr << "******** TEST 02 ********" << std::endl;
	using namespace std;
	
	Unique_ptr<int> u1(new int(1));
	Unique_ptr<int> u2(new int(1));


	int* a = u1.release();
	*a = 99;

	if (u1)
		cerr << "Puntatore u1 non vuoto" << endl;
	else
		cerr << "Puntatore u1 vuoto" << endl;
	
	std::cerr << std::endl;


	u2.reset();
	if (u2)
		cerr << "Puntatore u2 non vuoto" << endl;
	else
		cerr << "Puntatore u2 vuoto" << endl;

	std::cerr << std::endl;


	Unique_ptr<int> u3(new int(2));
	u2.swap(u3);
	if (u2)
		cerr << "Puntatore u2 non vuoto: " << *(u2.get()) << endl;
	else
		cerr << "Puntatore u2 vuoto" << endl;

	std::cerr << std::endl;

	struct Foo {
		void foo() {
			std::cerr << "chiamata a foo()" << std::endl;
		}
	};

	Unique_ptr<Foo> u4(new Foo);
	u4->foo();
}

int main(int argc, char const *argv[]) {
	test_01();
	std::cerr << std::endl;

	test_02();
	std::cerr << std::endl;
	return 0;
}