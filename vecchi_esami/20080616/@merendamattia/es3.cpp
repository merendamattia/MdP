#ifndef ANIMALE_HH
#define ANIMALE_HH

class Animale {
public:
    Animale();
    virtual ~Animale() { };
    virtual void verso() = 0;
    virtual Animale* clone() const = 0;
};

#endif

/*
Creiamo una classe astratta. Chi estenderà la classe avrà il compito di fare 
l'override dei metodi puri.
In questo modo:
`Animale a` -> errore 
*/