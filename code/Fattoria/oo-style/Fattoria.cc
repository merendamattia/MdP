#include "Animale.hh"
#include "Maker.hh"
#include "Canzone.hh"
#include <vector>
#include <iostream>

int main() {
  std::vector<Animale*> va;
  popola_fattoria(va);
  canta_canzone(std::cout, va);
  // NB: non siamo exception safe.
  svuota_fattoria(va);
  return 0;
}
