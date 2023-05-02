#ifndef CANZONE_HH_INCLUDE_GUARD
#define CANZONE_HH_INCLUDE_GUARD 1

#include "Animale.hh"
#include <vector>
#include <iosfwd>

void canta_canzone(std::ostream& os, const std::vector<Animale*>& va);

#endif // CANZONE_HH_INCLUDE_GUARD
