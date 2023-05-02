#ifndef BARBONCINO_HH_INCLUDE_GUARD
#define BARBONCINO_HH_INCLUDE_GUARD 1

#include "Cane.hh"

class Barboncino : public Cane {
public:
  virtual const char* verso() const;
};

#endif // BARBONCINO_HH_INCLUDE_GUARD

