#ifndef ANIMALE_HH_INCLUDE_GUARD
#define ANIMALE_HH_INCLUDE_GUARD 1

enum Genere {
  MASCHILE,
  FEMMINILE
};

class Animale {
public:
  virtual const char* nome() const = 0;
  virtual Genere genere() const = 0;
  virtual const char* verso() const = 0;
  virtual ~Animale();
};

#endif // ANIMALE_HH_INCLUDE_GUARD

