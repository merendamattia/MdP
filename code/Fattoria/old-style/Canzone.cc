#include "Canzone.hh"
#include "Animale.hh"

#include <cassert>
#include <ostream>
#include <string>
#include <vector>

namespace {

inline bool
vocale(const char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  default:
    return false;
  }
}

inline const char*
articolo_indet(const char* nome, Genere genere) {
  const char iniziale_nome = tolower(nome[0]);
  if (genere == MASCHILE) {
    switch (iniziale_nome) {
    case 'w': // Es., uno wapiti.
    case 'x': // Es., uno xifoforo.
    case 'y': // Es., uno yak.
    case 'z': // Es., uno zoglosso.
      return "uno ";
    case 's':
      if (vocale(tolower(nome[1])))
	// Es., un serpente.
	return "un ";
      else
	// Es., uno struzzo.
	return "uno ";
    default:
      // Es., un cane.
      return "un ";
    }
  }
  else {
    assert(genere == FEMMINILE);
    if (vocale(iniziale_nome))
      // Es., un'anatra.
      return "un'";
    else
      // Es., una mucca.
      return "una ";
  }
}

void
canta_strofa(std::ostream& os, const Animale& a) {
  const char* nome = a.nome();
  os << "Nella vecchia fattoria, ia ia oh!" << std::endl;
  os << "Quante bestie ha zio Tobia, ia ia oh!" << std::endl;
  os << "C'è " << articolo_indet(nome, a.genere()) << nome;

  os << " ...";
  os.flush();
  os << " " << a.verso();
  os.flush();

  os << std::endl;
  os << "Nella vecchia fattoria, ia ia oh!" << std::endl;
}

} // namespace


void
canta_canzone(std::ostream& os, const std::vector<Animale*>& va) {
  for (int i = 0, iend = va.size(); i != iend; ++i) {
    canta_strofa(os, *va[i]);
    os << std::endl;
  }
}

