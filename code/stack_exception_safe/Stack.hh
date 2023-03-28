#ifndef EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD
#define EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD 1

#include "Elem.hh"

#include <cassert>
#include <cstddef>
#include <string>

//! Una pila espandibile.
/*!
  Una struttura dati pila che si espande automaticamente al bisogno.
  L'implementazione assicura il livello <EM>strong</EM> di correttezza
  rispetto alle eccezioni, sotto le seguenti condizioni:
   - il tipo Elem fornisce il costruttore di default e l'operatore
     di assegnamento (per copia e per spostamento);
   - il distruttore di Elem non lancia eccezioni;
   - gli operatori di assegnamento di Elem sono exception safe;

   \note
   In questa prima versione, il tipo degli elementi Elem è fissato a priori.
*/
class Stack {
public:
  //! Un tipo intero senza segno adatto per le dimensioni.
  using size_type = std::size_t;

  //! Il tipo dei valori contenuti nello stack.
  using value_type = Elem;

  //! Costruttore di default.
  explicit Stack(size_type capacity = 16);

  //! Distruttore (livello nothrow).
  ~Stack();

  //! Costruttore di copia.
  Stack(const Stack& y);
  //! Assegnamento per copia.
  Stack& operator=(const Stack& y);

  //! Costruttore di spostamento (livello nothrow).
  Stack(Stack&& y) noexcept;
  //! Assegnamento per spostamento (livello nothrow).
  Stack& operator=(Stack&& y) noexcept;

  //! Scambio efficiente e senza eccezioni.
  void swap(Stack& y) noexcept;

  //! Mette una copia di \p elem in cima alla pila.
  void push(const value_type& elem);

  //! Rimuove il primo elemento della pila.
  void pop();

  //! Test di stack vuoto.
  bool is_empty() const;

  //! Accesso in lettura/scrittura al primo elemento.
  /*!
    Si assume che la pila non sia vuota. In caso di pila vuota
    il comportamento è indefinito.
  */
  value_type& top();

  //! Accesso in sola lettura al primo elemento.
  /*!
    Si assume che la pila non sia vuota. In caso di pila vuota
    il comportamento è indefinito.
  */
  const value_type& top() const;

  //! Numero di elementi sullo stack.
  size_type size() const;

  //! Controlla l'invariante della classe.
  /*!
    \return
    <CODE>true</CODE> se l'invariante di classe è soddisfatta;
    <CODE>false</CODE>, altrimenti.

    Utile per il debugging.
  */
  bool check_inv() const;

private:
  //! Puntatore alla memoria che contiene la pila.
  value_type* vec_;

  /*! \brief
    La capacita' attuale della pila (ovvero, il numero di elementi
    allocati a partire dall'indirizzo \p vec_).
  */
  size_type capacity_;

  /*! \brief
    La dimensione attuale della pila (ovvero, il numero di elementi
    significativi memorizzati in \p vec_).
  */
  size_type size_;

  // Funzioni di supporto per la gestione corretta dell'allocazione risorse.
  static value_type* make_copy(const value_type* src,
                               size_type src_size,
                               size_type dst_capacity);
  static value_type* make_move(value_type* src,
                               size_type src_size,
                               size_type dst_capacity);
};

////////////////////////////////////////////////////////////////////////////

inline
Stack::Stack(const size_type capacity)
  : vec_(nullptr), capacity_(capacity), size_(0) {
  if (capacity_ > 0)
    vec_ = new value_type[capacity_];
  assert(check_inv());
}

inline
Stack::Stack(const Stack& y)
  : vec_(make_copy(y.vec_, y.size_, y.capacity_)),
    capacity_(y.capacity_),
    size_(y.size_) {
  assert(check_inv());
}


inline
Stack::Stack(Stack&& y) noexcept
  : Stack(0) {
  assert(y.check_inv());
  swap(y);
  assert(check_inv());
}

inline
Stack::~Stack() {
  delete[] vec_;
}

inline void
Stack::swap(Stack& y) noexcept {
  using std::swap;
  swap(vec_, y.vec_);
  swap(size_, y.size_);
  swap(capacity_, y.capacity_);
}

inline Stack&
Stack::operator=(const Stack& y) {
  // Costruisco una copia di y e la scambio con this.
  Stack temp(y);
  swap(temp);
  return *this;
}

inline Stack&
Stack::operator=(Stack&& y) noexcept {
  assert(check_inv() && y.check_inv());
  Stack temp(std::move(y));
  swap(temp);
  assert(check_inv());
  return *this;
}

inline Stack::size_type
Stack::size() const {
  return size_;
}

inline bool
Stack::is_empty() const {
  return size() == 0;
}

inline const Stack::value_type&
Stack::top() const {
  // NOTA: è responsabilità del chiamante assicurarsi che
  // lo stack contenga almeno un elemento.
  assert(size_ > 0);
  return vec_[size_ - 1];
}

inline Stack::value_type&
Stack::top() {
  // NOTA: è responsabilità del chiamante assicurarsi che
  // lo stack contenga almeno un elemento.
  assert(size_ > 0);
  return vec_[size_ - 1];
}

inline void
Stack::pop() {
  // NOTA: è responsabilità del chiamante assicurarsi che
  // lo stack contenga almeno un elemento.
  assert(size_ > 0);
  --size_;
  assert(check_inv());
}

inline void
Stack::push(const value_type& elem) {
  if (size_ == capacity_) {
    // Devo espandere la struttura dati.
    size_type new_capacity = 2*size_ + 1;
    value_type* temp = make_move(vec_, size_, new_capacity);
    // Da qui (e fino alla fine del blocco) ho solo operazioni
    // che non possono lanciare eccezioni.
    delete[] vec_;
    vec_ = temp;
    capacity_ = new_capacity;
  }
  vec_[size_] = elem;
  ++size_;
  assert(check_inv());
}

#endif // EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD
