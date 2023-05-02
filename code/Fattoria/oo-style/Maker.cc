#include "Maker.hh"

#include "Mucca.hh"
#include "Gallina.hh"
#include "Gallo.hh"
#include "Cane.hh"
#include "Barboncino.hh"

#include <cstring>
#include <stdexcept>
#include <sstream>

namespace {


Animale* make_animale(const char* nome) {
  if (strcmp(nome, "cane") == 0)
    return new Cane();
  if (strcmp(nome, "mucca") == 0)
    return new Mucca();
  if (strcmp(nome, "gallina") == 0)
    return new Gallina();
  if (strcmp(nome, "gallo") == 0)
    return new Gallo();
  if (strcmp(nome, "barboncino") == 0)
    return new Barboncino();

  // Animale non supportato.
  std::stringstream ss;
  ss << "Animale " << nome << " non supportato";
  throw std::invalid_argument(ss.str());
  return 0;
}

} // namespace

void popola_fattoria(std::vector<Animale*>& va) {
  va.clear();
  va.push_back(make_animale("cane"));
  va.push_back(make_animale("mucca"));
  va.push_back(make_animale("gallina"));
  va.push_back(make_animale("gallo"));
  va.push_back(make_animale("barboncino"));
}

void svuota_fattoria(std::vector<Animale*>& va) {
  for (unsigned i = 0, i_end = va.size(); i != i_end; ++i)
    delete va[i];
  va.clear();
}

