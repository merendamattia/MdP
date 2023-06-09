#include <iostream>

class Base {
    public:
        Base() {
        std::cout << "Constructor Base::Base()" << std::endl;
        }
        Base(const Base&) {
        std::cout << "Constructor Base::Base(const Base&)" << std::endl;
        }
        virtual void f() {
        std::cout << "Base::f()" << std::endl;
        }
        virtual void g() {
        std::cout << "Base::g()" << std::endl;
        }
        void h() {
        std::cout << "Base::h()" << std::endl;
        }
        virtual ~Base() {
        std::cout << "Destructor Base::~Base()" << std::endl;
        }
};
class Derived : public Base {
    public:
        Derived() {
        std::cout << "Constructor Derived::Derived()" << std::endl;
        }
        Derived(const Derived&)
        : Base() {
        std::cout << "Constructor Derived::Derived(const Derived&)" << std::endl;
        }
        void f() {
        std::cout << "Derived::f()" << std::endl;
        }
        void h() {
            std::cout << "Derived::h()" << std::endl;
        }
        ~Derived() {
            std::cout << "Destructor Derived::~Derived()" << std::endl;
        }
};
int main() {
    Base b;
    Derived d;
    std::cout << "=== 0 ===" << std::endl;
    Base& rb = b;
    Base* pb = &d;
    Base b2 = *pb;
    Base* pb2 = &b2;
    std::cout << "=== 1 ===" << std::endl;
    b.f();
    rb.f();
    rb.h();
    std::cout << "=== 2 ===" << std::endl;
    d.f();
    d.g();
    d.h();
    std::cout << "=== 3 ===" << std::endl;
    pb->f();
    pb2->f();
    pb->g();
    pb->h();
    pb2->h();
    std::cout << "=== 4 ===" << std::endl;
    return 0;
}