#include <iostream>

class Square {
protected:
    double side;

public:
    Square(double side = 0) {
        this->side = side;
    }

    virtual double area() {
        return side * side;
    }

    void print() {
        std::cout << "Side: " << side << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};

class Cube : public Square {
public:
    Cube(double side = 0) : Square(side) {}

    virtual double area() {
        return 6 * Square::area();
    }

    double volume() {
        return side * side * side;
    }

    void print() {
        std::cout << "Side: " << side << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Volume: " << volume() << std::endl;
    }
};

int main() {
    Square s(5);
    s.print();

    Cube c(3);
    c.print();

    Square* ptr = &c;
    ptr->print();

    return 0;
}