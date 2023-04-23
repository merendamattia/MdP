#ifndef FOO_INT_HH
#define FOO_INT_HH

#include "../lib/Foo.hh"

extern template struct Foo<int>; // Pure declaration of a specialized class template
extern template struct Foo<char>; 

#endif // ! FOO_INT_HH