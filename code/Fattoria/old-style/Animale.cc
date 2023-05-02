#include "Animale.hh"

Animale::Animale(const char* nome,
                 Genere genere,
                 const char* verso)
  : nome_(nome), genere_(genere), verso_(verso) {
}

const char*
Animale::nome() const {
  return nome_.c_str();
}

Genere
Animale::genere() const {
  return genere_;
}

const char*
Animale::verso() const {
  return verso_.c_str();
}

