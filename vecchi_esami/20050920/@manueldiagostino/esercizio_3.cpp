#include <iostream>


class C1 {
public:
    C1() {
        std::cerr << "Constructor C1::C1()" << std::endl;
    }
    ~C1() {
        std::cerr << "Destructor C1::~C1()" << std::endl;
    }
};

class C2 {
public:
    C2() {
        std::cerr << "Constructor C2::C2()" << std::endl;
        throw 123;
    }
    ~C2() {
        std::cerr << "Destructor C2::~C2()" << std::endl;
    }
};

class C3 {
public:
    C3() {
        std::cerr << "Constructor C3::C3()" << std::endl;
    }
    ~C3() {
        std::cerr << "Destructor C3::~C3()" << std::endl;
    }
};

class D {
private:
    C1 c1;
    C2 c2;
    C3 c3_1;
    C3 c3_2;
public:
    D() : c1(), c2(), c3_1(), c3_2() {
        std::cerr << "Constructor D::D()" << std::endl;
    }
    ~D() {
        std::cerr << "Destructor D::~D()" << std::endl;
    }
};


int main() {
    try {
        D d;
    }
    catch (char c) {
        std::cerr << "char " << c << std::endl;
    }
    catch (...) {
        std::cerr << "..." << std::endl;
    }
    return 0;
}

/*  OUTPUT
 *  Constructor C1::C1()
 *  Constructor C2::C2()
 *  Destructor C1::~C1()
 *  ... 
 *  */
