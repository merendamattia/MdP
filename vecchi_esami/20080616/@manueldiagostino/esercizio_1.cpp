#include <string>
#include <iostream>
namespace N {
    class C {
    private:
        std::string s = "ciao";
        std::string& first() {std::cout<<"f1"<<std::endl; return s;}// funzione #1
    public:
        const std::string& first() const {std::cout<<"f2"<<std::endl; return s;} // funzione #2
        std::string& last() {std::cout<<"f3"<<std::endl; return s;}// funzione #3
        const std::string& last() const {std::cout<<"f4"<<std::endl; return s;}// funzione #4
        C(const char*) {std::cout<<"f5"<<std::endl;}// funzione #5
    }; // class C
    
    std::string s = "ciao_2";
    void print(const C&) {std::cout<<"f6"<<std::endl;}// funzione #6
    std::string& f(int) {std::cout<<"f7"<<std::endl; return s;}// funzione #7
} // namespace N


class A {
public:
    explicit A(std::string&) {std::cout<<"f8"<<std::endl;}// funzione #8
};


void print(const A&) {std::cout<<"f9"<<std::endl;}// funzione #9
//
void f(N::C& c) // funzione #10
{
    std::cout<<"f10"<<std::endl;
    ///* const std::string& f1 = */ c.first(); // chiamata #1 CAND{1,2} UTIL{1,2} MIGLI{1}
    ///* std::string& f2 = */ c.first(); // chiamata #2 CAND{1,2} UTIL{1,2} MIGLI{1} 
    /* const std::string& l1 = */ c.last(); // chiamata #3 CAND{3,4} UTIL{3,4} MIGLI{3} 
    /* std::string& l2 = */ c.last(); // chiamata #4 CAND{3,4} UTIL{3,4} MIGLI{3}
}
void f(const N::C& c) // funzione #11
{
    std::cout<<"f11"<<std::endl;
    /* const std::string& f1 = */ c.first(); // chiamata #5 CAND{1,2} UTIL{2} MIGLI{2}
    /* std::string& f2 = */ c.first(); // chiamata #6 CAND{1,2} UTIL{2} MIGLI{2}
    /* const std::string& l1 = */ c.last(); // chiamata #7 CAND{3,4} UTIL{4} MIGLI{4}
    /* std::string& l2 = */ c.last(); // chiamata #8 CAND{3,4} UTIL{4} MIGLI{4}
}

int main() {
    N::C c("begin");// chiamata #9 CAND{5} = UTIL = MIGLI
    f(c);// chiamata #10 CAND{11, 10, 7} UTIL{11, 10} MIGLI{10}
    f("middle");// chiamata #11 CAND{11,10} UTIL{11, 10} MIGLI{11}
    //print("end");// chiamata #12 CAND{9} UTIL{} MIGLI{}
}



