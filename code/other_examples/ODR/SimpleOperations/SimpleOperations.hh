#ifndef SIMPLE_OPERATIONS_HH
#define SIMPLE_OPERATIONS_HH

namespace SimpleOperations {
    class SimpleOperation {
        private:
        public:
            void printDel(void);
            void printWelcome(void);
            void printMex(const char*);

            // Templatic functions usually reside in a separate header file
            // It is good practice to separate implementations from declarations

            template<typename T, typename U>
            T doAdd(T& a, U& b) { T res; return res = a + b; }
            template<typename T, typename U>
            T doSub(T& a, U& b) { T res; return res = a - b; }
            template<typename T, typename U>
            T doMUl(T& a, U& b) { T res; return res = a * b; }
            template<typename T, typename U>
            T doDiv(T& a, U& b) { 
                T res;
                if (b == 0) return false;
                return res = a / b; 
            }
    };
}

#endif // SIMPLE_OPERATIONS_HH