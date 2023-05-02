#ifndef CANE_HH_INCLUDE_GUARD
#define CANE_HH_INCLUDE_GUARD 1

#include "Animale.hh"

class Cane : public Animale {
public:
  virtual const char* nome() const;
  virtual Genere genere() const;
  virtual const char* verso() const;
};

#endif // CANE_HH_INCLUDE_GUARD

