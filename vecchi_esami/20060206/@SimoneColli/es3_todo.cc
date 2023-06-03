#include <string>
using std::string;
class Manual_Generator {
    public:
        virtual void put(const string& s) = 0;
        virtual void set_boldface() = 0;
        virtual void reset_boldface() = 0;
    // ...
};
class HTML_Generator : public Manual_Generator {
    public:
        void put(const string& s);
        void set_boldface();
        void reset_boldface();
        void hyperlink(const string& uri, const string& text);
    // ...
};
class ASCII_Generator : public Manual_Generator {
    public:
        void put(const string& s);
        void set_boldface();
        void reset_boldface();
        void page_break();
    // ...
};



void f(Manual_Generator* mg_p) {
    // ...
    HTML_Generator* html_p = dynamic_cast<HTML_Generator*>(mg_p);
    if (html_p)
    html_p->hyperlink("http://www.cs.unipr.it/ppl", "PPL");
    else
    mg_p->put("PPL (http://www.cs.unipr.it/ppl)");
    // ...
    ASCII_Generator* ascii_p = dynamic_cast<ASCII_Generator*>(mg_p);
    if (ascii_p)
    ascii_p->page_break();
    else
    // Nota: usare il tag HR per simulare il cambio pagina in HTML.
    mg_p->put("<HR>");
    // ...
}