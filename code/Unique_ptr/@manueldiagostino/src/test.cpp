#include "../include/Unique_ptr.hh"

// g++ -D DEBUG -Wall -Wextra -I../include/ test.cpp -o a.out


// Allocation test
void
test_01() {
	Unique_ptr<int> u1;

	int* p1 = new int(10);
	std::cout << "*p1: " << *p1 << std::endl;
	Unique_ptr<int> u3(p1); // Unique_ptr(pointer&)
	if (!p1)
		std::cout << "p1 is now nullptr" << std::endl;
	std::cout << std::endl;


	Unique_ptr<int> u2(new int(1)); // Unique_ptr(pointer&&)

	u1 = std::move(u2); // operator=(Unique_ptr&&)

	int* p2 = new int(9);
	std::cout << "*p2: " << *p2 << std::endl;
	Unique_ptr<int> u4(std::move(p2));
	if (!p2)
		std::cout << "p2 is now nullptr" << std::endl;
	std::cout << std::endl;
}

// Functions test
void
test_02() {
	using namespace std;
	
	Unique_ptr<int> u1;
	Unique_ptr<int> u2(new int(1));


	// int* a = u2.get();


	if (u1){
		cerr << "Puntatore non vuoto" << endl;
	} else{
		cerr << "Puntatore vuoto" << endl;
	}
	
}

int main(int argc, char const *argv[]) {
	test_01();
	std::cout << std::endl;

	test_02();
	return 0;
}