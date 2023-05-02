#ifndef MUCCA_HH_INCLUDE_GUARD
#define MUCCA_HH_INCLUDE_GUARD 1

#include "Animale.hh"

class Mucca : public Animale {
public:
  virtual const char* nome() const;
  virtual Genere genere() const;
  virtual const char* verso() const;
};

#endif // MUCCA_HH_INCLUDE_GUARD

