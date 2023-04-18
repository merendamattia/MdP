```toc
```
---

## Overloading e template di funzione
Quando sono state introdotte le regole di risoluzione dell'overloading si era accennato al fatto che esistono regole speciali nel caso in cui alcune funzioni siano state ottenute come instanziazione o specializzazione di template di funzione.

Si ricorda che, in senso tecnico, <mark style="background: #FFB86CA6;">i template di funzione NON sono funzioni.</mark> 
Vale forse la pena riperterlo: sono degli schemi per generare, mediante istanziazione, un numero potenzialmente illimitato di funzioni vere e proprie.
Ad esempio, posso prendere l'indirizzo di una istanza del template, ma non esiste un indirizzo del template. 

Quindi quando si dice (informalmente) che un template di funzione è nell'insieme delle candidate nella risoluzione dell'overloading, in realtà si intende che una sua specifica istanza (o specializzazione totale) è candidata.

---

## Ordinamento parziale dei template di funzione
I template di funzione dotati dello stesso nome e visibili nello stesso scope (i.e., possono andare in overloading) sono ordinati parzialmente rispetto ad una relazione di *"specificità"*.
Anche in questo caso, la regola precisa è complicata e ne forniamo una versione semplificata.

Intuitivamente, denotiamo con
$$
istanze(X)
$$
l'insieme di tutte le possibili istanze del template $X$.
Allora si dice che <mark style="background: #ABF7F7A6;">il template di funzione X è più specifico del template di funzione Y</mark> se $istanze(X)$ è un sottoinsieme proprio di $istanze(Y)$.

---

## Regola speciale per i template di funzione
<mark style="background: #BBFABBA6;">Nella risoluzione dell'overloading, le istanze dei template più specifici sono preferite a quelle dei template meno specifici.</mark>
Per decidere se (una istanza di) un template di funzione entra nell'insieme delle candidate occorre verificare se è possibile effettuare la deduzione dei parametri del template. Durante il processo di deduzione *NON* si possono applicare promozioni, conversioni standard e conversioni definite dall'utente (in pratica, si possono applicare solo le corrispondenze esatte).

> Nota: se il processo di deduzione ha successo, allora l'istanza del template oltre ad essere candidata è anche utilizzabile.

Quando si cerca la migliore funzione utilizzabile, per quanto detto sopra, si devono eliminare le istanze ottenute da template di funzione meno specifici (che altrimenti causerebbero ambiguità).
Se anche dopo avere fatto questa rimozione continuiamo ad avere ambiguità, si eliminano dalle utilizzabili tutte le istanze di template. In questo modo, viene data una preferenza alle funzioni non templatiche.