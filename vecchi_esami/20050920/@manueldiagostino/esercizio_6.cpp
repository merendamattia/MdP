#include <iostream>
#include <memory>


class One {
    int i_one;
public:
    ~One() {std::cerr << "One dtor" << std::endl;}
};
class Two {
    int i_one;
    int i_two;
public:
    ~Two() {std::cerr << "Two dtor" << std::endl;}
};
class Three {
    int i_one;
    int i_two;
    int i_three;
};



class OneTwoThree {
private:
    One one;
    std::unique_ptr<Two> p_two;
    Three* p_three;
    // Dichiarati privati e non implementati.
    OneTwoThree(const OneTwoThree&);
    OneTwoThree& operator=(const OneTwoThree&);
public:
    OneTwoThree(const One& o, const Two& t) {
        one = o;
        p_two.reset(new Two(t));
        throw "s";
        p_three = new Three();
    }
    ~OneTwoThree() {
        
        delete p_three;
    }
};


int main (int argc, char *argv[]) {
    try {
        OneTwoThree ott(One{}, Two{});
    } catch (...) {
       return 1; 
    }
    
    return 0;
}
