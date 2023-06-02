/************ Inizio file Costante.hh ************/
class Costante {
public:
    static double pi;
    static double e;
    // ...
};
/************ Inizio file Costante.cc ************/
#include "Costante.hh"
Costante::pi = 3.1415;
Costante::e = 2.72;
// ...
/************ Inizio file Angolo.hh  ************/
class Angolo {
public:
    static double piatto;
    static double retto;
    static double giro;
    // ...
};
/************ Inizio file Angolo.cc  ************/
#include "Angolo.hh"
#include "Costante.hh"
Angolo::retto  = Costante::pi / 2;
Angolo::piatto = Costante::pi;
Angolo::giro   = Costante::pi * 2;
// ...

// Bisogna mettere le guardia in ogni header file.
// Bisogna mettere il tipo `double` davanti alle assegnazioni:
// Es: double Costante::pi = 3.1415;