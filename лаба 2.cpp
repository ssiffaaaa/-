#include <iostream>
#include <string>

class LongInteger {
private:
    unsigned long long high;
    unsigned long long low;

public:
    LongInteger(unsigned long long high = 0, unsigned long long low = 0) {
        this->high = high;
        this->low = low;
    }

    LongInteger(long long value) {
        this->high = (value < 0) ? -1 : 0;
        this->low = static_cast<unsigned long long>(value);
    }

    LongInteger(const std::string& str) {
        this->high = 0;
        this->low = 0;
        for (char c : str) {
            if (isdigit(c)) {
                this->low = this->low * 10 + (c - '0');
            }
        }
    }

    bool operator>(const LongInteger& other) const {
        if (this->high != other.high) {
            return this->high > other.high;
        }
        return this->low > other.low;
    }

    bool operator==(const LongInteger& other) const {
        return this->high == other.high && this->low == other.low;
    }

    LongInteger operator+(const LongInteger& other) const {
        LongInteger result;
        result.low = this->low + other.low;
        result.high = this->high + other.high + ((result.low < this->low) ? 1 : 0);
        return result;
    }

    std::string toString() const {
        std::string str;
        LongInteger value(*this);
        bool leadingZeros = true;
        while (value.high > 0) {
            unsigned long long digit = value.high % 10;
            if (digit != 0 || !leadingZeros) {
                leadingZeros = false;
                str = static_cast<char>('0' + digit) + str;
            }
            value.high /= 10;
        }
        unsigned long long lowValue = value.low;
        while (lowValue > 0 || str.empty()) {
            unsigned long long digit = lowValue % 10;
            str = static_cast<char>('0' + digit) + str;
            lowValue /= 10;
        }
        if (str.empty()) {
            str = "0";
        }
        return str;
    }
};
int main() {
    LongInteger a(123456789123456789ULL);
    LongInteger b("987654321987654321");

    std::cout << "A: " << a.toString() << std::endl;
    std::cout << "B: " << b.toString() << std::endl;

    if (a > b) {
        std::cout << "A > B" << std::endl;
    }
    else if (a == b) {
        std::cout << "A == B" << std::endl;
    }
    else {
        std::cout << "A < B" << std::endl;
    }

    LongInteger c = a + b;
    std::cout << "A + B: " << c.toString() << std::endl;

    return 0;
}