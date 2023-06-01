/*
 *  Vengono violati due principi della programmazione SOLID:
 *      1) Open-Close Principle: il programma è parzialmente aperto alle
 *      estensioni ma non chiuso rispetto alle modifiche; infatti, ogni qualvolta
 *      si volesse aggiungere un nuovo tipo di Expr, il codice stesso della classe e in 
 *      particolare quello dei metodi print() ed eval() andrebbero modificati e 
 *      ricompilati.
 *
 *      2) Liskov Substitution Principle: in questo caso il codice ad alto livello 
 *      (la classe Expr) dipende intrinsicamente dal tipo concreto kind (ossia 
 *      dettagli implementativi); questo approccio comporta appunto una violazione
 *      del principio Open-Close e una possibile fonte di bugs al momento della 
 *      manutenzione del codice.
 * */

// Expr.hh
#ifndef EXPR_HH
#define EXPR_HH

#include "Var_Bindings.hh"

class Expr {
public:
    
    virtual ~Expr() { }
    virtual int getType() = 0;
    virtual void print() = 0;
    virtual double eval(const Var_Bindings& vb) = 0;
};
#endif




// Si suppone che ogni .cpp abbia il relativo .hh con 
// l'interfaccia della corrispondente classe

// Const.cpp
#include <iostream>
#include "Expr.hh"

class Const : public Expr {
private:
    double value;
public:
    Const() : value(0) { }
    Const(double d) : value(d) { } // no explicit
    virtual ~Const() override { }

    virtual int getType() override { return 0; };
    virtual void print() override { std::cout << value; };
    virtual double eval() { return value; };
private:
    virtual double eval(const Var_Bindings& vb) { }
};



// Var.cpp
#include <iostream>
#include <string>
#include "Expr.hh"

class Var : public Expr {
private:
    std::string name;
public:
    Const() : name() { }
    explicit Const(const std::string& s) : name(s) { }
    virtual ~Const() override { }

    virtual int getType() override { return 1; };
    virtual void print() override { std::cout << name; };
    virtual double eval(const Var_Bindings& vb) override { return vb[name]; };
};



// Add.cpp
#include <iostream>
#include <string>
#include "Expr.hh"
#include "Var.hh"

class Add : public Expr {
private:
    Var arg1;
    Var arg2;
public:
    Const() : name() { }
    explicit Const(const std::string& s) : name(s) { }
    virtual ~Const() override { }

    virtual int getType() override { return 2; };
    virtual void print() override { arg1.print(); std::cout<<" + "; arg2.print(); };
    virtual double eval(const Var_Bindings& vb) override { 
        arg1.eval(vb) + arg2.eval(vb);    
    };
};



// Sub.cpp
#include <iostream>
#include <string>
#include "Expr.hh"
#include "Var.hh"

class Sub : public Expr {
private:
    Var arg1;
    Var arg2;
public:
    Const() : name() { }
    explicit Const(const std::string& s) : name(s) { }
    virtual ~Const() override { }

    virtual int getType() override { return 3; };
    virtual void print() override { arg1.print(); std::cout<<" - "; arg2.print(); };
    virtual double eval(const Var_Bindings& vb) override { 
        arg1.eval(vb) - arg2.eval(vb);    
    };
};
