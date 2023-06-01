#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
typedef std::vector<std::string>::const_iterator c_iter;

void f(const vect& v) {
    c_iter i = std::find(v.begin(), v.end(), "inizio"); 
    c_iter i_end = std::find(v.begin(), v.end(), "fine");
    while (i < i_end) {
        std::cout << *i << std::endl;
        ++i;
    }
}

void g(vect& v) {
    iter i = v.begin(), i_end = v.end();
    i = std::next(i);

    v.insert(i, "prima");
    std::cout << *i << std::endl;
    v.insert(i = std::next(i), "dopo");
    std::cout << *i << std::endl;
}

int main (int argc, char *argv[]) {
    std::vector<std::string> v;
    v.push_back("aaa");

    g(v);
    for (std::string& s : v) {
        std::cout << s << std::endl;
    }
    return 0;
}
