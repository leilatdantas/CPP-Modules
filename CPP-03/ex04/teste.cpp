#include <iostream>

class Base {
protected:
    int a, b, c;

public:
    Base(int a, int b, int c) : a(a), b(b), c(c) {}

    virtual void status() const {
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    }
};

class Derivada1 : virtual public Base {
public:
    Derivada1() : Base(1, 0, 3) {}  // Valores específicos para Derivada1 (0 em 'b' será sobrescrito)

    int getA() const { return a; }
    int getC() const { return c; }
};

class Derivada2 : virtual public Base {
public:
    Derivada2() : Base(0, 5, 0) {}  // Valores específicos para Derivada2 (0 em 'a' e 'c' será sobrescrito)

    int getB() const { return b; }
};

class Final : public Derivada1, public Derivada2 {
public:
    Final() : Base(0, 0, 0) {  // Inicializa com valores padrão
        // Inicializar os valores após as classes derivadas estarem completamente inicializadas
        a = Derivada1::getA();
        b = Derivada2::getB();
        c = Derivada1::getC();
    }

    void status() const  {
        std::cout << "Final - ";
        Base::status();
    }
};

int main() {
    Final obj;
    obj.status();  // Deve mostrar a: 1, b: 5, c: 3
    return 0;
}
