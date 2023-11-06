/*
    g++ -Wall -Wextra FuncArguments.cpp -o FuncArguments
*/
#include <iostream>
#include <string>

class Operations {
    public:
        std::string concatenateStrings(std::string a, std::string b) { return a + b; } // by value
        inline std::string betterconcatenateStrings(const std::string& a, const std::string& b) { return a + b; } // by reference

        int integerAddition(int a, int b) { return a + b; } // by value
        inline void integerPower2(int& a, int& b) { a *= a; b *= b; } // by reference
} aOp;

int main() {
    int a = 10, b = 20;
    int sum = aOp.integerAddition(a,b);
    aOp.integerPower2(a,b);

    std::cout << sum << '\n' << // 30
        a << " " << b << std::endl; // 100 400

    std::string s1 = "Hello";
    std::string s2 = "World!";
    std::string conc = aOp.betterconcatenateStrings(s1,s2);

    std::cout << conc << std::endl; // HelloWorld!

    return EXIT_SUCCESS;
}