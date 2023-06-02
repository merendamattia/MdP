#include <iostream>
namespace N{
    class A{
        public:
        
        A(const char* c){std::cerr<<"costruttore A\n";}
        ~A(){std::cerr<<"Distruttore A\n";}
        void f(int a){std::cerr<<"f int a\n";}
    };
}

void foo(N::A& a){std::cerr<<"foo(A& a)\n";}

void foo(const N::A& a){std::cerr<<"foo(const A& a)\n";}

int main(){
    N::A a("A");
    foo("abc");
    return 0;
}