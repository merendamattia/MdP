/*
 *  Il problema è in fase di creazione dell'oggetto di tipo OneTwoThree:
 *  in caso una delle acquisizioni delle risorse fallisse nel costruttore,
 *  si avrebbe un memory leak relativo alle altre risorse la cui allocazione
 *  non aveva presentato problemi (one, p_two); il distruttore di OneTwoThree
 *  infatti non verrà mai invocato in quanto l'oggetto non è mai stato 
 *  realmente costruito.
 *  */

#include <iostream>
#include <stdexcept>
class One {
    int i_one;
};
class Two {
    int i_one;
    int i_two;
};
class Three {
    int i_one;
    int i_two;
    int i_three;
};

class OneHandler {
private:
    One* one_;
public:
    OneHandler() noexcept : one_{nullptr} { }
    OneHandler(const One& other) : one_{new One{other}} { }
    OneHandler(One&& other) : one_{new One{other}} { }
    
    OneHandler& operator=(const OneHandler& other) {
        if (one_)
            delete one_;
        
        *one_ = *(other.one_);
        return *this;
    }

    OneHandler& operator=(OneHandler&& other) {
        if (one_)
            delete one_;
        
        one_ = other.one_;
        other.one_ = nullptr;
        return *this;
    }

    ~OneHandler() { 
        if (one_) 
            delete one_; 
        std::cerr << "one deleted" << std::endl;
    } 
};

class TwoHandler {
private:
    Two* two_;
public:
    TwoHandler() noexcept : two_{nullptr} { }
    TwoHandler(const Two& t) : two_{new Two{t}} { }
    TwoHandler(Two&& t) : two_{new Two{t}} { }

    TwoHandler& operator=(const TwoHandler& other) {
        if (two_)
            delete two_;
        
        *two_ = *(other.two_);
        return *this;
    }

    TwoHandler& operator=(TwoHandler&& other) {
        if (two_)
            delete two_;
        
        two_ = other.two_;
        other.two_ = nullptr;
        return *this;
    }

    ~TwoHandler() { 
        if (two_) 
            delete two_; 
        std::cerr << "two deleted" << std::endl;
    } 
};

class ThreeHandler {
private:
    Three* three_;
public:
    ThreeHandler() noexcept : three_{nullptr} { }
    ThreeHandler(const Three& t) : three_{new Three{t}} { }
    ThreeHandler(Three&& t) : three_{new Three{t}} { }

    ThreeHandler& operator=(const ThreeHandler& other) {
        if (three_)
            delete three_;
        
        *three_ = *(other.three_);
        return *this;
    }

    ThreeHandler& operator=(ThreeHandler&& other) {
        if (three_)
            delete three_;
        
        three_ = other.three_;
        other.three_ = nullptr;
        return *this;
    }

    ~ThreeHandler() { 
        if (three_) 
            delete three_; 
        std::cerr << "three deleted" << std::endl;
    } 
};

class OneTwoThree {
private:
    OneHandler one_;
    TwoHandler two_;
    ThreeHandler three_;

    // Dichiarati privati e non implementati.
    OneTwoThree(const OneTwoThree&);
    OneTwoThree& operator=(const OneTwoThree&);
public:
    // non essendo richiesto, non implemento altri costruttori
    OneTwoThree(const One& o, const Two& t) { // costruisce i membri tramite costruttori di default
        one_ = OneHandler(o);
        try {
            two_ = TwoHandler(t);
            try {
                three_ = ThreeHandler(Three{}); 
            } catch (...) {
                two_.~TwoHandler();
                throw;
            }
        } catch (...) {
            one_.~OneHandler();
            throw;
        }
    }

    ~OneTwoThree() = default; 
};


int main (int argc, char *argv[]) {
    OneTwoThree ott{One {}, Two {}};
    return 0;
}




////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
