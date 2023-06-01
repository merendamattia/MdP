class Animale {
public:
    Animale() = default;
    Animale(const Animale& other) = default;

    virtual Animale* clone() const = 0;
    virtual void verso() const = 0;
    virtual ~Animale() { }
};
