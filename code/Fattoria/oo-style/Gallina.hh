#ifndef GALLINA_HH_INCLUDE_GUARD
#define GALLINA_HH_INCLUDE_GUARD 1

#include "Animale.hh"

class Gallina : public Animale {
public:
  const char* nome() const override;
  Genere genere() const override;
  const char* verso() const override;
};

#endif // GALLINA_HH_INCLUDE_GUARD

