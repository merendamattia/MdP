# Helloworld
1. [A cosa serve questo programma?](#a-cosa-serve-questo-programma)
2. [Fasi di compilazione](#fasi-compilazione-c)
3. [Ricapitolando](#ricapitolando)

---

## A cosa serve questo programma?

Lo scopo di questo programma, in realtà, è quello di effettuare un test sulla corretta installazione dell'ambiente di sviluppo scelto per il C++.  
Ovvero, ci si vuole assicurare di avere un compilatore funzionante, le librerie di sistema correttamente installate, eccetera.

Dal nostro punto di vista, comunque, questo semplice programma si presta bene ad evidenziare la differenza che esiste tra una conoscenza superficiale del linguaggio C++ ed una conoscenza un po' più approfondita. 

Esempi di domande (<b>_da esame_</b>):
 * perché la funzione `main` è dichiarata per restituire un valore intero?
 * perché non esiste la corrispondente istruzione di `return`?
 * perché devo qualificare il nome (`cout`) del canale di output con `std`?
 * che cosa indica `std`?
 * qual è la differenza tra queste due varianti?
     `std::cout << "Hello, world!" << std::endl;`
   vs
     `std::cout << "Hello, world!\n";`
 * che cosa è `iostream`?
 * perché devo includere `iostream`?
 * perché devo usare le parentesi angolate (e non le virgolette)
   quando includo `iostream`?
 * a cosa si riferiscono le due occorrenze dell'operatore infisso `<<` ?
 * sono invocazioni di operatori built-in o si tratta di funzioni
   definite dall'utente?
  

Esempio di helloworld:
```c++
#include <iostream>

int main(){
	std::cout << "Hello, world!" << std::endl;
}
```

_[Torna all'indice](#helloworld)_

---

## Fasi compilazione C++:
In senso lato, il processo di compilazione prende in input file sorgente e/o librerie e produce in output file eseguibili o librerie.  

Per fare ciò, il compilatore (in senso lato) esegue vari passi:

1) il preprocessore elabora il codice dei file sorgente e produce una unità di traduzione
 ```shell
g++ -Wall -Wextra -E helloworld.cpp -o main.preproc.cpp
```

2) il compilatore (in senso stretto) elabora l'unità di traduzione e produce il codice assembler
```shell
g++ -Wall -Wextra -S main.preproc.cpp -o main.asm
```

3) l'assemblatore elabora il codice assembler e produce il cosiddetto file oggetto (object file)
```shell
g++ -Wall -Wextra -c helloworld.cpp -o main.o
```

4) il linker effettua il collegamento tra i vari file oggetto e le librerie al fine di ottenere un file eseguibile o una libreria.
```shell
g++ -Wall -Wextra -c helloworld.cpp -o main
```	

_[Torna all'indice](#helloworld)_

---

## Ricapitolando
Giunti al termine di questa discussione su `"Hello, world!"` è forse il caso di ricapitolare alcuni concetti chiave.

1) Tecnicamente, quando si dice che un programma è formato da un solo file sorgente, si commette un errore; come abbiamo visto, anche un programma banale come `"Hello, world!"` necessita di oltre un centinaio di header file di sistema (il numero esatto dipende dall'implementazione specifica usata), oltre a `helloworld.cpp`;

2) I programmi "veri" sono formati da numerosi file sorgente, anche quando si escludono gli header file di sistema; è necessario comprendere i meccanismi che consentono di separare il programma in diversi file sorgente, per poi compilarli separatamente e infine collegarli in modo corretto; occorre inoltre imparare come compilare e collegare correttamente un programma che dipenda da librerie software di terze parti (ovvero, diverse dalla libreria standard del C++).

3) In generale, ogni volta che si scrive qualche linea di codice è necessario chiedersi qual è la sua funzione, evitando di dare la risposta: "Non ne ho idea, so solo che si è sempre fatto così". <b>_Questa è la risposta di un programmatore che NON sa risolvere eventuali problemi tecnici che si dovessero presentare e deve per forza chiedere consiglio a programmatori più esperti_</b>. La nostra ambizione dovrebbe essere quella di (iniziare il lungo cammino per) diventare noi stessi programmatori esperti e sapere come affrontare i problemi tecnici legati alla programmazione. Si noti che queste competenze sono ben separate ed indipendenti rispetto alla conoscenza dello specifico dominio applicativo per il quale si è deciso di sviluppare uno strumento software.

_[Torna all'indice](#helloworld)_