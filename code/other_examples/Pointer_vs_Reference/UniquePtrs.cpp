/*
    g++ -gdwarf-4 UniquePtrs.cpp -o UniquePtrs.out
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val_log.txt  -v ./UniquePtrs.out
*/
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void printDel() { cout << "----\n"; }

/** @brief Purposefully leaks 4 bytes of memory */
void aLeakage() {
    int* somePtr = new int(1);
    if (*somePtr == 1) {
        cout << "'*somePointer' is indeed equal to " << *somePtr << endl;
        return; // Here comes the leak
    }
    delete somePtr;
}

/** @brief Creates a unique pointer to integer, initializing the value */
void noLeakage() {
    // std::unique_ptr<int> someSmartPtr; someSmartPtr.reset(new int(1));
    std::unique_ptr<int> someSmartPtr(new int(1));
    if (*someSmartPtr == 1) {
        cout << "'*someSmartPtr' is indeed equal to " << *someSmartPtr << endl;
        return; // The leak is no more
    }
}

/** @brief Tries to copy a unique pointer of some type */
template<typename T>
void tryCopyU(std::unique_ptr<T> u_ptr) {
    cout << "tryCopyU()" << endl;
}

/** @brief Tries to copy a shared pointer of some type */
template<typename T>
void tryCopyS(std::shared_ptr<T> s_ptr) {
    cout << "tryCopyS()" << endl;
}

/** @brief Takes 2 shared pointers: operations may be not exception safe*/
template<typename T, typename U>
void tryShared(std::shared_ptr<T> shr_ptr_1, std::shared_ptr<U> shr_ptr_2 ){
    cout << "tryShared()" << endl;
}

/** @brief Checks wether the weak pointer is still available */
template<typename T>
void isAvailable(std::weak_ptr<T> weak_ptr) {
    if (auto shared_ptr = weak_ptr.lock())
        cout << *shared_ptr << endl;
    else cout << "No more available!" << endl;
} 

class MyClass {
    public:
        MyClass() { cout << "MyClass::ctor()" << endl; }
        virtual ~MyClass() { cout << "MyClass::dtor()" << endl; }

        virtual void someMethod() { cout << "MyClass::someMethod()" << endl; }
};
class MyDerived : public MyClass {
    public:
        MyDerived() { cout << "MyDerived::ctor()" << endl; }
        ~MyDerived() { cout << "MyDerived::dtor()" << endl; }

        void someMethod() override { cout << "MyDerived::someMethod()" << endl; }
};
class MyAlpha : public MyClass {
    public:     
        MyAlpha() { cout << "MyAlpha::ctor()" << endl; }
        ~MyAlpha() { cout << "MyAlpha::dtor()" << endl; }

        void someMethod() override { cout << "MyAlpha::someMethod()" << endl; }
};
class MyBeta : public MyAlpha {
    public:
        MyBeta() { cout << "MyBeta::ctor()" << endl; }
        ~MyBeta() { cout << "MyBeta::dtor()" << endl; }

        void someMethod() override { cout << "MyBeta::someMethod()" << endl; }
};

int main() {
    MyClass* MC = new MyClass;
    std::unique_ptr<MyClass> MC_ptr(new MyClass);
    std::unique_ptr<MyDerived> MD_ptr(new MyDerived);
    std::shared_ptr<MyAlpha> MA_ptr(new MyAlpha);
    std::shared_ptr<MyBeta> MB_ptr(new MyBeta);
    std::weak_ptr<int> weak_ptr;

    printDel();

    // aLeakage();
    noLeakage();

    printDel();

    MC_ptr->someMethod();
    MD_ptr->someMethod();
    // tryCopy(MC_ptr);             // COPY is DISALLOWED
    tryCopyU(std::move(MC_ptr));    // MOVE is ALLOWED
                                    // 'MC_ptr' does manage no resource now
    MC_ptr.reset(MC);                       // 'MC_ptr' now points to object of type 'MyClass'
    MyDerived* MD = MD_ptr.get();           // 'MD' points to the resource managed by the unique pointer 'MD_ptr'
    MyDerived* new_MD = MD_ptr.release();   // 'new_MD' raw pointer now manages the resource once managed by the unique pointer
    
    printDel();

    tryCopyS(MA_ptr);               // COPY is ALLOWED
    tryCopyS(std::move(MA_ptr));    // MOVE is ALLOWED
                                    // 'MA_ptr' counter will reach 0, deletion is automatic

    printDel();

    tryShared(MA_ptr, MB_ptr);                                              // This is not exception safe code (resource and resource management are 2 separate things) 
    tryShared(std::make_shared<int>(1), std::make_shared<double>(3.1415));  // This is exception safe code (guaranteed by 'std::make_shared<>')
    
    printDel();

    isAvailable(weak_ptr);          // 'weak_ptr' is no longer available

    printDel();

    MC_ptr.release();
    delete MC; delete new_MD;
    return 0;
}