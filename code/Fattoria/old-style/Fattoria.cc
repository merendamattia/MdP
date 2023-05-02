#include "Animale.hh"
#include "Maker.hh"
#include "Canzone.hh"

#include <iostream>
#include <vector>

int main() {
  // NB: non ci interessa essere exception safe.
  std::vector<Animale*> va;
  popola_fattoria(va);
  canta_canzone(std::cout, va);
  svuota_fattoria(va);
  return 0;
}
