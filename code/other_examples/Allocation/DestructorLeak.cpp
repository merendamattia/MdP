// From: esame 07/09/2022
// Esempio di memory leak causato da distruttore dichiarato non virtuale

/*
    clang++ -gdwarf-4 DestructorLeak.cpp -o DestructorLeak.out
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val_log.txt  -v ./DestructorLeak.out
*/
#include <iostream>

using std::cout;
using std::endl;

struct A {
  A() { cout << "constr::A" << endl; }
  ~A() { cout << "destr::A" << endl; }
  // virtual ~A() { cout << "destr::A" << endl; } 
};

struct B : public A {
  int* pi;
  B() { cout << "constr::B" << endl; pi = new int; }
  ~B() { cout << "destr::B" << endl; delete pi; }
  // B() { cout << "constr::B" << endl; }
  // ~B() { cout << "destr::B" << endl; }
};

int main() {
  A *pb = new B();

  delete pb;
}

/* OUTPUT with memory leak */
// constr::A
// constr::B
// destr::A

/* VALGRIND LOG */
// 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
// operator new(unsigned long) (vg_replace_malloc.c:434)
// B::B() (DestructorLeak.cpp:21)
// main (DestructorLeak.cpp:28)


// OUTPUT without memory leak
// constr::A
// constr::B
// destr::B
// destr::A