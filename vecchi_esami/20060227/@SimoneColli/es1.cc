#include<iostream>

void foo(int*){std::cerr<<"funzione 1\n";}// Funzione #1

template <typename T>
void foo(const T&){std::cerr<<"funzione 2\n";}// Funzione #2

template <typename T>
void foo(T, T){std::cerr<<"funzione 3\n";}// Funzione #3

template <typename T, typename U>
void foo(T, U){std::cerr<<"funzione 4\n";}// Funzione #4

template <typename T>
void foo(const T*, T){std::cerr<<"funzione 5\n";}// Funzione #5

template <typename T, typename U>
void foo(T*, U){std::cerr<<"funzione 6\n";}// Funzione #6

namespace A {
    struct Delta {
        Delta(double = 0) {};
    };
    template <typename T>
    void bar(T, double){std::cerr<<"funzione 7\n";}// Funzione #7
    template <typename T, typename U>
    void bar(T, U){std::cerr<<"funzione 8\n";}// Funzione #8
} // namespace A

template <typename T>
void bar(T, const A::Delta&){std::cerr<<"funzione 9\n";} // Funzione #9

int main() {
    int alfa;
    const int* p_alfa = &alfa;
    double beta;
    long gamma;
    A::Delta delta;
    
    foo(&alfa, beta);// chiamata A c:{[1, 6]} u:{4, 6} m:{6}
    foo(&alfa, alfa);// chiamata B c:{[1, 6]} u:{4, 5, 6} m:{5} ? -> 6
    foo(p_alfa, alfa);// chiamata C c:{[1, 6]} u:{4, 5, 6} m:{5}
    foo(alfa, p_alfa);// chiamata D c:{[1, 6]} u:{4} m:{4}
    
    foo(alfa);// chiamata E c:{[1, 6]} u:{2} m:{2}
    
    foo(&alfa);// chiamata Fc :{[1, 6]} u:{1, 2} m:{1}
    
    foo(p_alfa);// chiamata G c:{[1, 6]} u:{2} m:{2}
    
    foo(const_cast<int*>(p_alfa)); // chiamata H c:{[1, 6]} u:{1, 2} m:{1}

    
    bar(gamma, gamma);// chiamata I c:{9} u:{} m:{} -> 9

    bar(delta, alfa);// chiamata L c:{9, 7, 8} u:{9, 7, 8} m:{7} -> 8
    bar(delta, beta);// chiamata M c:{9, 7, 8} u:{9, 7, 8} m:{7}
    A::bar(beta, gamma);// chiamata N c:{7, 8} u:{8} m:{8}
    
    return 0;
}