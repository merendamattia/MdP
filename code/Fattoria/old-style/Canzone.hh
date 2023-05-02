#ifndef CANZONE_HH_INCLUDE_GUARD
#define CANZONE_HH_INCLUDE_GUARD 1

#include "Animale.hh"

#include <iosfwd>
#include <vector>

void canta_canzone(std::ostream& os, const std::vector<Animale*>& va);

#endif // CANZONE_HH_INCLUDE_GUARD
