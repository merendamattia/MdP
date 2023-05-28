#ifndef EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD
#define EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD 1

#include <cstddef>
#include <utility>
#include <cassert>
#include <iostream>

// new, delete, new[], delete[]

// allocazione memoria grezza:    operator new / operator new[]
// costruzione senza allocazione: new di piazzamento     new (ptr) T(...);

// distruzione esplicita (senza deallocazione):  vec_[i].~T();
// deallocazione memoria grezza:  operator delete / operator delete[]


// Nota: tutti i dati e le funzioni membro sono pubblici:
// questa classe NON fornisce una interfaccia verso l'utente.

// Mantiene al suo interno *esattamente* size_ elementi.
// Per le posizioni di indice i tali che size_ <= i < capacity_,
// abbiamo la memoria grezza allocata, ma non abbiamo oggetti costruiti.

template <typename T>
struct Stack_Impl {
  using size_type = std::size_t;

  T* vec_;
  size_type size_;
  size_type capacity_;

  // Controllo invariante di classe: vogliamo consentire il caso
  // di stack di capacità zero. Nota: non è possibile controllare che
  // lo stack contenga effettivamente size_ elementi.
  bool check_inv() const {
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

  void make_empty() noexcept {
    // Distrugge esplicitamente gli elementi effettivamente presenti
    // (senza deallocazione memoria grezza).
    for (size_type i = size_; i-- > 0; )
      vec_[i].~T();
    // Dealloca la memoria grezza.
    operator delete(vec_);
    // Manteniamo l'invariante di classe.
    vec_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  Stack_Impl() noexcept
  : vec_(nullptr), size_(0), capacity_(0) {}

  explicit Stack_Impl(size_type capacity)
    // Nota: uso del "delegating constructor" per ottenere uno stack vuoto.
    : Stack_Impl() {
    if (capacity == 0)
      return;
    // Allocazione memoria grezza.
    vec_ = static_cast<T*>(operator new(sizeof(T) * capacity));
    capacity_ = capacity;
  }

  void swap(Stack_Impl& y) noexcept {
    using std::swap;
    swap(vec_, y.vec_);
    swap(size_, y.size_);
    swap(capacity_, y.capacity_);
  }

  // Disabilitazione operatori di copia.
  Stack_Impl(const Stack_Impl&) = delete;
  Stack_Impl& operator=(const Stack_Impl&) = delete;

  // Move constructor: crea uno stack vuoto e poi lo scambia con y,
  // di fatto "rubando" le risorse di y.
  Stack_Impl(Stack_Impl&& y) noexcept
    : Stack_Impl() { swap(y); }

  // Move assignment: rilascia le risorse dello stack (ripristina lo stato
  // al caso di stack vuoto) e poi "ruba" le risorse a y.
  Stack_Impl& operator=(Stack_Impl&& y) noexcept {
    make_empty();
    swap(y);
    return *this;
  }

  // Distruttore: svuota lo stack.
  ~Stack_Impl() { make_empty(); }

}; // struct Stack_Impl



// Classe utilizzabile dall'utente: *usa* Stack_Impl per gestire le risorse
// e fornisce l'interfaccia dello Stack.

template <typename T>
class Stack {
public:
  using size_type = typename Stack_Impl<T>::size_type;

  explicit Stack(size_type capacity = 16) : impl(capacity) {
    assert(check_inv());
  }

  // Costruttore di copia.
  Stack(const Stack& y) : impl(y.impl.capacity_) {
    // Copio solo gli size_ elementi effettivamente presenti.
    for (size_type i = 0; i < y.impl.size_; ++i) {
      // new di piazzamento: costruisce un T all'indirizzo specificato,
      // senza allocare nuova memoria grezza.
      new (impl.vec_ + i) T(y.impl.vec_[i]);
      // Aggiorno *immediatamente* il numero di elementi presenti;
      // essenziale per l'exception safety.
      ++impl.size_;
    }
    assert(check_inv());
  }

  void swap(Stack& y) noexcept {
    impl.swap(y.impl);
    assert(check_inv());
    assert(y.check_inv());
  }

  // Assegnamento per copia: uso costruttore copia + swap.
  Stack& operator=(const Stack& y) {
    Stack tmp(y);
    swap(tmp);
    return *this;
  }

  // Move ctor, move assignment e distruttore: quelli di default vanno bene
  // (invocano le corrisoondenti operazioni su Stack_Impl).
  Stack(Stack&& y) = default;
  Stack& operator=(Stack&& y) = default;
  ~Stack() = default;

  size_type size() const { return impl.size_; }

  bool is_empty() const { return size() == 0; }

  T& top() {
    assert(size() > 0);
    return impl.vec_[impl.size_ - 1];
  }

  const T& top() const {
    assert(size() > 0);
    return impl.vec_[impl.size_ - 1];
  }

  bool check_inv() const { return impl.check_inv(); }

  void push(const T& elem) {
    if (impl.size_ == impl.capacity_)
      reallocate(impl.capacity_ * 2 + 1);
    // Nota: new di piazzamento; una *copia* di T viene costruita
    // direttamente all'indirizzo specificato (senza allocazione).
    new (impl.vec_ + impl.size_) T(elem);
    ++impl.size_;
  }

  void push(T&& elem) {
    if (impl.size_ == impl.capacity_)
      reallocate(impl.capacity_ * 2 + 1);
    // Nota: new di piazzamento; elem viene *spostato* (notare std::move)
    // direttamente all'indirizzo specificato (senza allocazione).
    new (impl.vec_ + impl.size_) T(std::move(elem));
    ++impl.size_;
  }

  void pop() {
    assert(size() > 0);
    --impl.size_;
    // Distruzione esplicita (senza deallocazione memoria grezza).
    impl.vec_[impl.size_].~T();
  }

private:
  Stack_Impl<T> impl;

  void reallocate(size_type new_capacity) {
    assert(impl.size_ <= new_capacity);
    Stack tmp(new_capacity);
    // Nota: usiamo la push con rvalues (spostamenti e non copie).
    for (size_type i = 0; i < impl.size_; ++i)
      tmp.push(std::move(impl.vec_[i]));
    swap(tmp);
  }

}; // class Stack

#endif // EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD
