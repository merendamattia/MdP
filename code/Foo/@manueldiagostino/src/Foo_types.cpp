#include "../lib/Foo.cpp"

/* 
 * Explicit instantiation of the template for the specific `int` type.
 * This forces the compiler to add the specialized code of the class template.
 */
template class Foo<int>;
template class Foo<char>;
