Il problema è la possibile inclusione ripetuta dei file header perché mancano le guardie contro le inclusioni.

```cpp
/************ Inizio file Costante.hh ************/
#ifndef INCLUDE_GUARD_COSTANTE_HH
#define INCLUDE_GUARD_COSTANTE_HH
class Costante {
	public:
		static double pi;
		static double e;
		// ...
};
#endif
/************ Inizio file Costante.cc ************/
#include "Costante.hh"
static double Costante::pi = 3.1415;
static double Costante::e = 2.72;
// ...

/************ Inizio file Angolo.hh ;************/
#ifndef INCLUDE_GUARD_ANGOLO_HH
#define INCLUDE_GUARD_ANGOLO_HH
class Angolo {
	public:
		static double piatto;
		static double retto;
		static double giro;
		// ...
};
#endif
/************ Inizio file Angolo.cc ************/
#include "Angolo.hh"
#include "Costante.hh"
static double Angolo::retto = Costante::pi / 2;
static double Angolo::piatto = Costante::pi;
static double Angolo::giro = Costante::pi * 2;
// ...
```