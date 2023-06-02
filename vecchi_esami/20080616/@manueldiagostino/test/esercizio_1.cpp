
#include <iostream>
#include <ostream>
class A {
public:
    int d;
    A(int i) : d{i} { std::cout << "A ctor(" << d << ")" << std::endl; }
    virtual ~A() { std::cout << "A dtor(" << d << ")" << std::endl; }
};

void foo(A& a) { std::cout << "foo(A& a)" << std::endl; }
void foo(const A& a) { std::cout << "foo(const A& a)" << std::endl; }


int main (int argc, char *argv[]) {
    A a(3);

    foo(5);
    return 0;
}
