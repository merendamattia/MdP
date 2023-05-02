#include "Maker.hh"

#include <stdexcept>
#include <cstring>
#include <sstream>

namespace {

Animale* make_animale(const char* nome) {
  if (strcmp(nome, "cane") == 0)
    return new Animale("cane", MASCHILE, "bau");
  if (strcmp(nome, "mucca") == 0)
    return new Animale("mucca", FEMMINILE, "muuu");
  if (strcmp(nome, "gallina") == 0)
    return new Animale("gallina", FEMMINILE, "coccodè");
  if (strcmp(nome, "gallo") == 0)
    return new Animale("gallo", MASCHILE, "chicciricchì");

  // Animale non supportato.
  std::stringstream ss;
  ss << "Animale " << nome << " non supportato";
  throw std::invalid_argument(ss.str());
  return 0;
}

} // namespace

void popola_fattoria(std::vector<Animale*>& va) {
  va.clear();
  va.push_back(make_animale("mucca"));
  va.push_back(make_animale("gallo"));
  va.push_back(make_animale("cane"));
  va.push_back(make_animale("gallina"));
  va.push_back(make_animale("cane"));
}

void svuota_fattoria(std::vector<Animale*>& va) {
  for (unsigned i = 0, i_end = va.size(); i != i_end; ++i)
    delete va[i];
  va.clear();
}
