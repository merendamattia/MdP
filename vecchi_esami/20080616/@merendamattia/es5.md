## Esercizio 5, esame 2008

1. "Non causa perdite di risorse".
    Un esempio di violazione è la seguente:
    ```cpp
    int* x = new int(5);
    throw std::exception();
    ```
    In questo caso, al verificarsi dell'eccezione, le risorse precedentemente ottenute non vengono gestite correttamente. Lanciata l'eccezione, avremo un memory leak di `x`.

2. "È neutrale rispetto alle eccezioni".
    Un esempio di violazione è la seguente:
    ```cpp
    int* x = new int(5);
    try {
        int y = new int(6);
        try{
            something(x,y);
            // eccezione
        } catch(...) { delete y; }
    } catch(...) { delete x; }
    ```
    Quando si verificherà l'eccezione e verrà catturata, `y` verrà rilasciata correttamente. 
    Fin qua va tutto bene. 
    I problemi vengono a galla quando dentro il catch in cui viene liberata `y`, l'eccezione non viene propagata: 
    `x` non verrà rilasciata e avremo un memory leak.

3. "Lascia gli oggetti utilizzati in uno stato consistente".
    Un esempio di violazione è la seguente:
    Apro un file, effettuo una modifica, si verifica una eccezione e non chiudo il file.
    In questo caso, lo stato del file sarà inconsistente, in quanto rimanendo aperto potrebbe causare perdite di dati o altri problemi.
