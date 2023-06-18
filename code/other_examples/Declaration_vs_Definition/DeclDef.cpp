/*
    gcc -Wall -Wextra DeclDef.cpp -o DeclDef
*/
#include <iostream>

// TEMPLATES
template <typename T> struct pureTemplate;
template <typename T> struct definedTemplate {
    T t;
};
template <typename T> T pureTemplateFunc(T t1, T t2);
template <typename T> T definedTemplateFunc(T t1, T t2) { return t1 + t2; };

// STRUCTS
struct amEmpty; // pure declaration
struct amFull{ int anInteger; float aFloat; } oneFull; // definition
struct S{ int aMember; } anS, *paMember(&anS);

// DATA TYPES
int undefined; // declaration
amEmpty* amEmptyPointer; // opaque pointer

// FUNCTIONS
void declaredFunc(int a);
void definedFunc(int a) { std::cout << "Uh"; }

int main() {
    
    oneFull.anInteger = 1, oneFull.aFloat = 3.1415;
    anS.aMember = 2, paMember -> aMember = 3;

    std::cout << oneFull.anInteger << anS.aMember << paMember -> aMember << std::endl; // 133

    return 0;
}