#include <iostream>
#include <cmath>

using namespace std;

class Double {
private:
    double value;

public:
    void init() {
        value = 0.0;
    }

    void read() {
        cout << "Введите двойное значение: ";
        cin >> value;
    }

    void display() {
        cout << "Значение: " << value << endl;
    }

    void add(double num) {
        value += num;
    }

    void subtract(double num) {
        value -= num;
    }

    double power(int exponent) {
        return pow(value, exponent);
    }
};

int main() {
    setlocale(0, "Ru");
    Double d;
    d.init();
    d.read();
    d.display();

    cout << "Добавлениe 2.5 к значению..." << endl;
    d.add(2.5);
    d.display();

    cout << "Вычитание 1.0 от значения..." << endl;
    d.subtract(1.0);
    d.display();

    cout << "Значение возведено в степень 3: " << d.power(3) << endl;

    return 0;
}