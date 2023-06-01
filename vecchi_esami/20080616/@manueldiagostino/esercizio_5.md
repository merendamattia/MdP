# Esercizio 5

1. Non causa perdite di risorse

```cpp
{
    int* pi_1 = new int;
    int* pi_2 = new int;

    delete pi_1;
    delete pi_2;
}
```

Se la `new` di `pi_2` dovesse fallire, vi sarebbe un memory leak relativo alla risorsa puntata da pi_1.

2. È neutrale rispetto alle eccezioni

```cpp
{
    int* pi_1 = new int;
    try {
        int* pi_2 = new int;
    } 
    catch (...) {
        delete pi_1;
    }

    delete pi_1;
    delete pi_2;
}
```

Elimina correttamente la memoria riservata a pi_1 in caso di eccezioni ma non rilancia verso l'esterno l'eccezione catturata nel blocco try-catch.

3. lascia gli oggetti in uno stato consistente

```cpp

// class MyContainer
void push_back(const elem& e) {
    if (size == capacity) {
        auto old_ptr = this->data;
        capacity = 2*capacity + 1;
        this->data = new elem[2*capacity+1];
    }

    data[size++] = e;
}
```

Nel caso la `new` fallisse, il valore di `capacity` sarebbe aggiornato (sebbene il valore reale non sia `2*capacity + 1`) prima di aver avuto successo nel riservare la nuova memoria, con un conseguente _undefined behaviour_ in fase di scrittura `data[size++]`.
