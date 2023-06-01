class BasicProtocol {
private:
    /*...*/
public:
    BasicProtocol();
    virtual ~BasicProtocol();
    bool BasicMsgA( /*...*/ );
    bool BasicMsgB( /*...*/ );
    bool BasicMsgC( /*...*/ );
};

class Protocol1 {
private:
    BasicProtocol bs;
public: 
    Protocol1();
    ~Protocol1();
    bool DoMsg1( /*...*/ );
    bool DoMsg2( /*...*/ );
    bool DoMsg3( /*...*/ );
};
class Protocol2 {
private:
    BasicProtocol bs;
public:
    Protocol2();
    ~Protocol2();
    bool DoMsg1( /*...*/ );
    bool DoMsg2( /*...*/ );
    bool DoMsg3( /*...*/ );
    bool DoMsg4( /*...*/ );
    bool DoMsg5( /*...*/ );
};

/*
Bisogna eliminare la derivazione dei due protocolli rispetto a BasicProtocol:
non avremo più una relazione "IS-A" ma bensì una relazione "HAS-A".
*/