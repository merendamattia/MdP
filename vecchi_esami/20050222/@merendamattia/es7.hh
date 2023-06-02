#ifndef MY_CONTAINER_GUARD_HH
#define MY_CONTAINER_GUARD_HH

template <typename T>
class Container {
private:
    T* ps;
    unsigned int sz;
public:
    Container() : sz(0), ps(nullptr);
    explicit Container(int size) : sz(size), ps(new T[size]);
    explicit Container(const Container& other);
    explicit Container(Container&& other);
    Container& operator=(const Container& other);
    Container& operator=(Container&& other);
    virtual ~Container() { delete [] ps; }
};

#endif