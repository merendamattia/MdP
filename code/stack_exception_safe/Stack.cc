#include "Stack.hh"
#include <iostream>

Stack::value_type*
Stack::make_copy(const value_type* src,
                 size_type src_size, size_type dst_capacity) {
  assert(dst_capacity >= src_size);
  if (dst_capacity == 0)
    return nullptr;
  // Allochiamo la risorsa.
  value_type* dst = new value_type[dst_capacity];
  try {
    // Proviamo a copiare gli elementi da `src' a `dest'.
    for (size_type i = 0; i < src_size; ++i)
      dst[i] = src[i];
  }
  catch (...) {
    // Qualcosa è andato storto.
    // Deallochiamo la risorsa ...
    delete[] dst;
    // ... e rilanciamo l'eccezione per essere neutrali.
    throw;
  }
  return dst;
}

Stack::value_type*
Stack::make_move(value_type* src, size_type src_size, size_type dst_capacity) {
  assert(dst_capacity >= src_size);
  if (dst_capacity == 0)
    return nullptr;
  // Allochiamo la risorsa.
  value_type* dst = new value_type[dst_capacity];
  // Spostiamo gli elementi da `src' a `dest'.
  for (size_type i = 0; i < src_size; ++i)
    dst[i] = std::move(src[i]);
  return dst;
}

bool
Stack::check_inv() const {
  if (capacity_ == 0 && vec_ != nullptr) {
#ifndef NDEBUG
    std::cerr << "Lo Stack è dichiarato avere una capacità "
      "nulla ma ha risorse allocate!" << std::endl;
#endif // NDEBUG
    return false;
  }
  if (size_ > capacity_) {
#ifndef NDEBUG
    std::cerr << "Lo Stack è dichiarato avere una dimensione "
	      << "superiore alla capacità!" << std::endl;
#endif // NDEBUG
    return false;
  }
  if (capacity_ > 0 && vec_ == nullptr) {
#ifndef NDEBUG
    std::cerr << "Non vi sono risorse allocate per lo Stack!"
	      << std::endl;
#endif // NDEBUG
    return false;
  }
  // Tutto ok.
  return true;
}
