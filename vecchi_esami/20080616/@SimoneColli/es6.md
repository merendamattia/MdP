Discutere brevemente sotto quali condizioni il codice seguente si può considerare exception safe

```cpp
void foo(Sched& v, Sched& w, unsigned n) {  
	get_mutex_for(v);  
	try {  
		get_mutex_for(w);  
		try {  
			transmit(v, w, n);  
			release_mutex_for(w);  
			release_mutex_for(v);  
		}  
		catch (...) {  
			release_mutex_for(w);  
			throw;  
		}  
	}  
	catch (...) {  
		release_mutex_for(v);  
		throw;  
	}  
}  
```

Il codice è considerabile exception safe nel caso in cui:
- le funzioni release_mutex_for non lancino eccezioni
- trasmit non causi la terminazione del programma


Fornire una codifica alternativa basata sull’idioma “l’acquisizione di risorse è una inizializzazione”.

RAII-RRID:
```cpp
#incliude <memory> // unique_ptr
void foo(Sched& v, Sched& w, unsigned n) {
	auto mv = std::make_unique(v);
	auto mw = std::make_unique(w);
	transmit(mv.get(), mw.get(), n); 
}  
```
In caso di uscita eccezionale verranno chiamati i distruttori degli unique_ptr che libereranno v e w 
