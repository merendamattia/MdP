#ifndef GALLO_HH_INCLUDE_GUARD
#define GALLO_HH_INCLUDE_GUARD 1

#include "Animale.hh"

class Gallo : public Animale {
public:
  virtual const char* nome() const;
  virtual Genere genere() const;
  virtual const char* verso() const;
};

#endif // GALLO_HH_INCLUDE_GUARD

