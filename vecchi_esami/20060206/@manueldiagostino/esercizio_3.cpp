/*
 * Sebbene sia stato sfruttato il meccanismo di astrazione e inversione delle dipendenze
 * (Dependency inversion principle), il codice in questione viola l'open-close principle;
 * infatti, ogni qualvolta sia necessario aggiungere un nuovo formato di documentazione, 
 * il codice di f() va modificato e ciò potrebbe comportare eventuali bug nel software già scritto
 * precedentemente. Inoltre la struttura di f() presuppone che esistano soltanto due tipi di 
 * documentazione (HTML e ASCII).
 * */

// Soluzione: aggiungere un metodo virtuale 'doc_generator()'
#include <string>
using std::string;

class Manual_Generator {
public:
    virtual void put(const string& s) = 0;
    virtual void set_boldface() = 0;
    virtual void reset_boldface() = 0;
    virtual void doc_generator() = 0;
    // ...
};

class HTML_Generator : public Manual_Generator {
public:
    void put(const string& s) override { /* ... */ }
    void set_boldface() override { /* ... */ }
    void reset_boldface() override { /* ... */ }
    void hyperlink(const string& uri, const string& text) { /* ... */ }
    void doc_generator() override {
        hyperlink("http://www.cs.unipr.it/ppl", "PPL");
        put("<HR>");
    }
    // ...
};

class ASCII_Generator : public Manual_Generator {
public:
    void put(const string& s) override { /* ... */ }
    void set_boldface() override { /* ... */ }
    void reset_boldface() override { /* ... */ }    
    void page_break() { /* ... */ }
    void doc_generator() override {
        put("PPL (http://www.cs.unipr.it/ppl)");
        page_break();    
    }
    // ...
};

void f(Manual_Generator* mg_p) {
    mg_p->doc_generator();
}
