#ifndef INLINEFUNC
#define INLINEFUNC

#include <atomic>

inline int int_sum(int a, int b) {
    return a + b;
}

int int_sub(int a, int b) {
    return a - b;
}

inline std::atomic<int> counter(0); // one thread reads, the other writes

#endif //INLINEFUNC