#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
typedef std::vector<std::string>::const_iterator c_iter;

void f(const vect& v) {
    c_iter i = std::find(v.begin(), v.end(), "inizio");
    // errore perché si prova ad assegnare un iteratore const a un iteratore non const
    c_iter i_end = std::find(v.begin(), v.end(), "fine");
    while(i < i_end) {
        std::cout << *i << std::endl;
        ++i;
    }
}
void g(vect& v) {
    iter i = v.begin(), i_end = v.end();

    if(++i <= i_end)
        v.insert(i, "prima");

    if(++i <= i_end)
        v.insert(i, "dopo");

    // if(!v.empty()){

    //     v.insert(++i, "prima");
    //     v.insert(i, "dopo");
    //     ++i;
    //     // v.insert(++i, "dopo");
    // }
}
int main(){
    vect v;
    v.push_back("inizio");
    f(v);
    g(v);
    f(v);
    return 0;
}
