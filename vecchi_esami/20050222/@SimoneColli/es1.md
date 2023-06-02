```cpp
void f(const char* s); // funzione #1

template <typename T>
void f(T t); // funzione #2


template <typename T>
void f(T t1, T t2); // funzione #3

template <typename T, typename U>
void f(T t, U u); // funzione #4

template <typename T>
void f(T* pt, T t); // funzione #5

template <typename T, typename U>
void f(T* pt, U u); // funzione #6



template <typename T>
void g(T t, double d); // funzione #7

template <typename T>
void g(T t1, T t2); // funzione #8

int test() {
    f(’a’); // chiamata #1
    f("aaa"); // chiamata #2

    int i; 
    
    f(i); // chiamata #3
    f(i, i); // chiamata #4
    f(i, &i); // chiamata #5
    f(&i, i); // chiamata #6
    
    double d;
    
    f(i, d); // chiamata #7
    f(&d, i); // chiamata #8
    
    long l;
    
    g(l, i); // chiamata #9
    g(l, l); // chiamata #10
    g(l, d); // chiamata #11
    g(d, d) ;// chiamata #12
}
```

| Chiamata | Candidata        | Utilizzabili | Migliore | Note                                                                  | Correzione |
| -------- | ---------------- | ------------ | -------- | --------------------------------------------------------------------- | ---------- |
| 1        | 1, 2, 3, 4, 5, 6 | 2            | 2        | no conversione da 'a' a "a"                                           |            |
| 2        | 1, 2, 3, 4, 5, 6 | 1, 2         | 1        | la 1 è più specifica della 2                                          |            |
| 3        | 1, 2, 3, 4, 5, 6 | 2            | 2        | la 1 è per i const char*                                              |            |
| 4        | 1, 2, 3, 4, 5, 6 | 3, 4         | 3        | 3 è più specifica della 4 perché sia t1 che t2 sono dello stesso tipo |            |
| 5        | 1, 2, 3, 4, 5, 6 | 4            | 4        |                                                                       |            |
| 6        | 1, 2, 3, 4, 5, 6 | 4,5,6        | 5        |                                                                       |            |
| 7        | 1, 2, 3, 4, 5, 6 | 4            | 4        |                                                                       |            |
| 8        | 1, 2, 3, 4, 5, 6 | 4, 6         | 6        |                                                                       |            |
| 9        | 7, 8             | 7            | 7        |                                                                       |            |
| 10       | 7,8              | 8            | 8        |                                                                       |            |
| 11       | 7,8              | 7            | 7        |                                                                       |            |
| 12       | 7,8              | 7            | 7        |                                                                       |   utilizzabili 7,8 -> Ambigua         |
