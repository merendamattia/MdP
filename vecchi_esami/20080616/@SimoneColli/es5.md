Una porzione di programma si dice exception safe (versione base) se fornisce le seguenti garanzie anche in presenza di eccezioni: 

- non causa perdite di risorse;  
- è neutrale rispetto alle eccezioni;  
- lascia gli oggetti utilizzati in uno stato consistente. 

Per ognuna delle garanzie elencate, fornire un semplice esempio di violazione, spiegandone brevemente le conseguenze.

1. Il seguente codice non libera la memoria allocata dinamicamente prima dell'eccezione

```cpp
struct B{
	B(){
		throw 123;
	}
};
void foo(){
	int* A = new int(42);
	try{
		B = new B();
	}
	catch(...){
		// non gestisce l'eccezione localmente
		// assenza delete A;
		throw;
	}
}
```

La mancanza del `delete A` non permette il corretto rilascio e conseguente deallocazione della memoria allocata per A, causando così memory leak, ovvero perdite di memoria causate del mancato rilascio.

2. Il seguente codice non è neutrale rispetto alle eccezioni
```cpp
struct B{
	B(){
		throw 123;
	}
};
void foo(){
	int* A = new int(42);
	try{
		B = new B();
	}
	catch(...){
		// gestisce l'eccezione localmente
		delete A;
		// assenza di throw
	}
}
```

Il codice non è neutrale rispetto le eccezioni, perché dopo averne catturata e gestita una non la rilancia `throw` e quindi non ne permette la propagazione.

3. Il seguente codice non lascia l'oggetto in uno stato consistente:

```cpp
class A{
	private:
		int* A;
		int syze = 0;
	public:
		A(int s){
			syze = s;
			A = new int[s]; // eccezione mancanza memoria => A = nullptr
		}
}
int main(){
	A a;
	return 0;
}
```
Il codice mostra una situazione inconsistente perché `syze` sarà uguale a `10` ma la dimensione effettiva dell'array è 0.