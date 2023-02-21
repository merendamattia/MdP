#include <iostream>
using namespace std;

int main(){
	cout << "Hello, world!" << endl;
}

/*

Fasi compilazione c++:
1) Preprocessing: prende il file sorgente e lo elabora producendo l'unità di traduzione
	g++ -Wall -Wextra -E helloworld.cpp -o main.preproc.cpp
2) Compilazione stretta: prende l'unità di traduzione e produce il codice assembler
	g++ -Wall -Wextra -S main.preproc.cpp -o main.asm
3) Assemblaggio: prende il codice assebler e produce il codice oggetto
	g++ -Wall -Wextra -c helloworld.cpp -o main.o
4) Collegamento (linker): prende il codice oggetto e produce il codice eseguibile (o libreria) 
	g++ -Wall -Wextra -c helloworld.cpp -o main
	
*/