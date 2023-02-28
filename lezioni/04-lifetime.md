# Tempo di vita (lifetime)
==TODO: indice e ritorna all'indice==
Abbiamo visto come il concetto di scope consenta di stabilire in quali punti del codice (_dove_) è visibile il nome introdotto da una dichiarazione.  
Oltre alla dimensione spaziale, è necessario prendere in considerazione anche la dimensione temporale, per stabilire in quali momenti (_quando_) è legittimo interagire con determinate entità.

Alcune entità (tipi di dato, funzioni, etichette) possono essere riferite in qualunque momento durante l'esecuzione del programma.  
Un oggetto memorizzato in memoria, invece, è utilizzabile solo dopo che è stato creato e soltanto fino a quando viene distrutto, ovvero ogni accesso è valido solo durante il suo tempo di vita (lifetime).

### Nota 
Anche se il codice eseguibile delle funzioni è memorizzato in memoria, tecnicamente le funzioni _NON_ sono considerate oggetti in memoria e quindi non se ne considera il lifetime.

Il _tempo di vita_ di un oggetto è influenzato dal modo in cui questo viene creato.  
Gli oggetti in memoria sono creati:
 - da una _definizione_ (non basta una dichiarazione pura);
 - da una _chiamata dell'espressione `new`_ (oggetto nell' heap, senza nome);
 - dalla _valutazione di una espressione_ che crea implicitamente un nuovo oggetto (oggetto temporaneo, senza nome).

Il tempo di vita di un oggetto:
  1) inizia quando **_termina_** la sua costruzione, che è composta da due fasi distinte:
     - allocazione della memoria "grezza";
     - inizializzazione della memoria (quando prevista);
  2) termina quando **_inizia_** la sua distruzione, che è anch'essa composta da due fasi distinte:
     - invocazione del distruttore (quando previsto);
     - deallocazione della memoria "grezza".

Si noti che un oggetto la cui costruzione NON termina con successo, NON avendo iniziato il suo tempo di vita, NON dovrà terminarlo, ovvero per quell'oggetto NON verrà eseguita la distruzione.

Si noti anche che DURANTE le fasi di creazione e di distruzione di un oggetto si è fuori dal suo tempo di vita, per cui le operazioni che è possibile effettuare sull'oggetto sono molto limitate (le regole del linguaggio sono complicate e comprendono numerosi casi particolari, che per il momento non è opportuno approfondire).