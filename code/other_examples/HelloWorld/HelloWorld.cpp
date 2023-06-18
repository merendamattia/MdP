/*	Per generare i codici presi in esame in Lezione1

	g++ -E HelloWorld.cpp -o HelloWorld.preproc.cpp &&\
	g++ -S HelloWorld.cpp -o HelloWorld.assembler.cpp &&\
  	g++ -c HelloWorld.cpp -o HelloWorld.o &&\
	g++ HelloWorld.cpp -o HelloWorld
*/
#include <iostream>

int main() {
	std::cout << "Hello, world!" << std::endl;
}