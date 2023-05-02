#ifndef ANIMALE_HH_INCLUDE_GUARD
#define ANIMALE_HH_INCLUDE_GUARD 1

#include <string>

enum Genere {
  MASCHILE,
  FEMMINILE
};

class Animale {
public:
  Animale(const char* nome,
          Genere genere,
          const char* verso);

  const char* nome() const;
  Genere genere() const;
  const char* verso() const;

private:
  std::string nome_;
  Genere genere_;
  std::string verso_;
};

#endif // ANIMALE_HH_INCLUDE_GUARD

