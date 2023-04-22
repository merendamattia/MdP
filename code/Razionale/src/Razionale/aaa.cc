#include <cassert>

// compilazione: g++ -Wall -Wextra aaa.cc -o aaa

int main(){
    int i = 1;
    int j = i;
    assert(j <= 0);
    // il comando -DNDEBUG in fase di compilazione nasconde tutte le asserzioni
}