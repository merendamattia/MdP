#ifndef T_HH_INCLUSION_GUARD
#define T_HH_INCLUSION_GUARD 1

#include <string>
#include <cassert>
#include <stdexcept>
#include <iostream>

class T {
private:
  static const int max_num_objects = 100;
  static int num_current_objects;

  static int next_id() {
    static int next_id_ = 0;
    return ++next_id_;
  }

  static void register_object(int id) {
    if (num_current_objects == max_num_objects) {
      std::cerr << "TROPPI OGGETTI!!!!" << std::endl;
      throw std::invalid_argument("Troppi oggetti!");
    } else {
      std::cerr << "   Creato id = " << id
                << " (attualmente ne abbiamo " << (num_current_objects+1) << ")"
                << std::endl;
      ++num_current_objects;
    }
  }

  static void unregister_object(int id) noexcept {
    if (id == 0)
      return;
    assert(num_current_objects > 0);
    --num_current_objects;
    std::cerr << "   Distrutto id = " << id
              << " (ve ne sono ancora " << num_current_objects << ")"
              << std::endl;
  }

  int id_;
  std::string s_;

public:
  T() : id_(next_id()), s_() { register_object(id_); }
  T(const char* s) : T() { s_ = s; }

  T(const T& y) : T() { s_ = y.s_; }
  T& operator=(const T& y) {
    s_ = y.s_;
    return *this;
  }

  T(T&& y) noexcept
    : id_(y.id_), s_(std::move(y.s_)) { y.id_ = 0; }

  T& operator=(T&& y) noexcept {
    unregister_object(id_);
    id_ = y.id_;
    s_ = std::move(y.s_);
    y.id_ = 0;
    return *this;
  }

  ~T() { unregister_object(id_); }

  friend bool operator==(const T& x, const T& y) { return x.s_ == y.s_; }
};

#endif // T_HH_INCLUSION_GUARD
