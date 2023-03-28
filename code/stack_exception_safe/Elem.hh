#ifndef ELEM_HH_INCLUSION_GUARD
#define ELEM_HH_INCLUSION_GUARD 1

#include <string>

// La classe Elem tiene traccia del numero di istanze create/distrutte.
// In ogni momento ne possono esistere al massimo `max_num_objects'.

class Elem {
private:
  static const int max_num_objects = 100;
  static int num_current_objects;

  static int next_id();
  static void register_object(int id);
  static void unregister_object(int id);

  int id_;
  std::string s_;

public:
  Elem();
  Elem(const Elem& y);
  Elem& operator=(const Elem& y);
  Elem(Elem&& y);
  Elem& operator=(Elem&& y);
  ~Elem();

  // Conversione implicita.
  Elem(const char* s);
  friend bool operator==(const Elem& x, const Elem& y);
};

#endif // ELEM_HH_INCLUSION_GUARD
