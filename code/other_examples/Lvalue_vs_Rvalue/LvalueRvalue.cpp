/*
    g++ -Wall -Wextra LvalueRvalue.cpp -o LvalueRvalue.cpp
*/
#include <iostream>

struct Object {
    Object() { std::cout << "Object::ctor" << std::endl; }
    ~Object() { std::cout << "Object::dtor" << std::endl; }
    
    Object(const Object& arg) { std::cout << "Object::copy_ctor" << std::endl; *this = arg; }
    Object& operator=(const Object& arg) { std::cout << "Object::copy_assgn" << std::endl; return *this; }
    Object(Object&& arg) { std::cout << "Object::move_ctor" << std::endl; *this = std::move(arg); }
    Object& operator=(Object&& arg) { std::cout << "Object::move_assgn" << std::endl; return *this; }

} defaultObject; // Object::ctor

void foo(const int& d){
    std::cout << "std::cout << d;" << std::endl;
}

void bar() {
    foo(0.5);  // rvalue becomes lvalue
}

int main() {
    int i, ai[10] = {7}; // lvalues
    ai[5] = 5 + 1; // rvalue

    bar(); // std::cout << d;
    
    Object newObject = defaultObject;   // Object::copy_ctor
                                        // Object::copy_assgn
    Object anotherObject = std::move(defaultObject);    // Object::move_ctor
                                                        // Object::move_assgn

    // Object::dtor x3
    return 0;
}