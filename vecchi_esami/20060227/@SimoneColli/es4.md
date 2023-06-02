Motivare brevemente l’introduzione delle guardie contro l’inclusione ripetuta dei file di intestazione, enunciando chiaramente la regola del linguaggio che verrebbe violata nel caso di un loro mancato (o scorretto) utilizzo. Scrivere un esempio, minimale ma completo, di codice che non si comporta correttamente a causa dell’assenza di tali guardie.


L'introduzione delle guardie contro l'inclusione ripetuta è necessaria per riuscire a mantenere il principio della one definition rule. Questo principio richiede in uno dei suoi punti che per ogni unità di traduzione sia presente al più una definizione per ogni variabile, funzione, enumerazione, classe o template.

_Esempio_
```cpp
// file esempio.hh
class esempio{
	// ...
};

// file gestore_esempi.hh
#include "esempio.hh"
class gestore_esempi{
	// ...
};

// file user.cc
#include "esempio.hh" //! <- inclusione ripetuta
#include "gestore_esempi.hh"
// ...
```