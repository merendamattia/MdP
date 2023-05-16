  
## Alcune questioni tecniche sul polimorfismo dinamico
Abbiamo visto che, nel caso di polimorfismo dinamico, le classi astratte sono tipicamente formate da metodi virtuali puri, più il distruttore della classe che è dichiarato virtuale, ma non puro. In alcuni casi è però necessario complicare il progetto (ad esempio, usando l'ereditarietà multipla): quando lo si fa, si corre il rischio di incorrere in errori ed è quindi opportuno cercare le risposte ad alcune domande tecniche sul polimorfismo dinamico, che possono diventare rilevanti quando viene utilizzato al di fuori dei confini stabiliti nei nostri semplici esempi.

1) Ci sono metodi che NON possono essere dichiarati virtuali? In particolare, cosa si può dire sulla possibilità o meno di rendere virtuali le seguenti categorie di metodi:
	  - costruttori
	  - distruttori
	  - funzioni membro (di istanza, cioè non statiche)
	  - funzioni membro statiche
	  - template di funzioni membro (non statiche)
	  - funzioni membro (non statiche) di classi templatiche
2) Come faccio a costruire una copia di un oggetto concreto quando questo mi viene fornito come puntatore/riferimento alla classe base?
3) Cosa succede se si invoca un metodo virtuale durante la fase di costruzione o di distruzione di un oggetto?
4) Come funziona l'ereditarietà multipla quando NON ci si limita al caso delle interfacce astratte?
	   - scope e ambiguità
	   - classi base ripetute
	   - classi base virtuali
	   - semantica speciale di inizializzazione
5) Quali sono gli usi del polimorfismo dinamico nella libreria standard?
	   - classi eccezione standard
	   - classi iostream