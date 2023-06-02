#ifndef MY_SET_GUARD_HH
#define MY_SET_GUARD_HH

#include <iostream>

template <typename T>
class Set {
private:
    std::list<T> my_list_;
public:
    // Costruisce l’insieme vuoto.
    Set();
    // Costruisce il singoletto che contiene t.
    Set(T&& t);
    Set(const T& t);

    Set(Set&& y);
    Set(const Set& y);

    void operator=(Set&& y);
    void operator=(const Set& y);

    virtual ~Set();

    unsigned int size() const;
    bool is_empty() const;
    bool contains(const Set& y) const;
    
    const T& min();
    T min();
    
    void pop_min();
    
    void insert(const T& z);
    void insert(T&& z);

    void union_assign(const Set& y);
    
    void intersection_assign(const Set& y);
    
    void swap(Set&& y);  
};

template <typename T>
std::ostream& 
operator<<(std::ostream& os, const Set<T>& other);

#endif