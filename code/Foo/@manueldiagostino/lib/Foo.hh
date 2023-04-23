#ifndef PROVA_HH
#define PROVA_HH

template <typename T>
struct Foo {
	void foo();
};

/*
 * Declaration of specialized class for `char` type.
 */
template<>
struct Foo<char> {
	void foo();
};

#endif // ! PROVA_HH