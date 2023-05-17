
#include <iostream>
#include <string>
struct Generatore_Doc {
    virtual void stampa(const std::string& s) = 0;
    virtual void hyperlink(const std::string& uti, const std::string& testo) = 0;
    virtual void grassetto(bool mode) = 0;
    virtual void corsivo(bool mode) = 0;
    virtual void salto_pagina() = 0;
    virtual ~Generatore_Doc() {}
};


// #include Generatore_Doc.hh
struct Generatore_PDF : public Generatore_Doc {
    void stampa(const std::string& s) override;
    void hyperlink(const std::string& uti, const std::string& testo) override;
    void grassetto(bool mode) override ;
    void corsivo(bool mode) override ;
    void salto_pagina() override;
    virtual ~Generatore_PDF() {}
};

// #include Generatore_Doc.hh
struct Generatore_HTML : public Generatore_Doc{
    void stampa(const std::string& s) override;
    void hyperlink(const std::string& uti, const std::string& testo) override;
    void grassetto(bool mode) override ;
    void corsivo(bool mode) override ;
    void salto_pagina() override;
    virtual ~Generatore_HTML() {}
};
