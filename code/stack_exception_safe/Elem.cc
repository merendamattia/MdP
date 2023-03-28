#include "Elem.hh"

#include <cassert>
#include <stdexcept>
#include <iostream>

int Elem::num_current_objects = 0;

void
Elem::register_object(int id) {
  if (num_current_objects == max_num_objects) {
    std::cerr << "TROPPI OGGETTI!!!!" << std::endl;
    throw std::invalid_argument("Troppi oggetti!");
  }
  else {
    std::cerr << "   Creato id = " << id
	      << " (attualmente ne abbiamo " << (num_current_objects+1) << ")"
	      << std::endl;
    ++num_current_objects;
  }
}

void
Elem::unregister_object(int id) {
  assert(num_current_objects > 0);
  --num_current_objects;
  std::cerr << "   Distrutto id = " << id
	    << " (ve ne sono ancora " << num_current_objects << ")"
	    << std::endl;
}

int
Elem::next_id() {
  static int next_id_ = 0;
  return next_id_++;
}

Elem::Elem()
  : id_(next_id()), s_() {
  register_object(id_);
}

Elem::Elem(const Elem& y)
  : id_(next_id()), s_(y.s_) {
  register_object(id_);
}

Elem::Elem(Elem&& y)
  : id_(next_id()), s_(std::move(y.s_)) {
  register_object(id_);
}

Elem::Elem(const char* s)
  : id_(next_id()), s_(s) {
  register_object(id_);
}

Elem&
Elem::operator=(const Elem& y) {
  // Nota: non sovrascriviamo l'id dell'oggetto.
  s_ = y.s_;
  return *this;
}

Elem&
Elem::operator=(Elem&& y) {
  // Nota: non sovrascriviamo l'id dell'oggetto.
  s_ = std::move(y.s_);
  return *this;
}

Elem::~Elem() {
  try {
    // unregister_object() scrive su std::cerr.
    // Questa operazione di output, fatta a solo scopo didattico,
    // se non opportunamente mascherata dal try/catch potrebbe
    // causare comportamento scorretto in presenza di eccezioni.
    unregister_object(id_);
  }
  catch (...) {
    // I distruttori non devono MAI lasciar propagare eventuali
    // eccezioni da loro generate.
  }
}

bool
operator==(const Elem& x, const Elem& y) {
  // Non confrontiamo l'id.
  return x.s_ == y.s_;
}

