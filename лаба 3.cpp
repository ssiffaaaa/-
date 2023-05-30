#include <iostream>
#include <sstream>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int hours = 0, int minutes = 0, int seconds = 0) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    Time(const std::string& str) {
        std::stringstream ss(str);
        char c;
        ss >> this->hours >> c >> this->minutes >> c >> this->seconds;
    }

    Time(long long seconds) {
        this->hours = seconds / 3600;
        seconds %= 3600;
        this->minutes = seconds / 60;
        seconds %= 60;
        this->seconds = seconds;
    }

    int toSeconds() const {
        return this->hours * 3600 + this->minutes * 60 + this->seconds;
    }

    bool operator>(const Time& other) const {
        return this->toSeconds() > other.toSeconds();
    }

    bool operator==(const Time& other) const {
        return this->toSeconds() == other.toSeconds();
    }

    Time operator+(long long seconds) const {
        return Time(this->toSeconds() + seconds);
    }

    Time operator-(long long seconds) const {
        return Time(this->toSeconds() - seconds);
    }

    Time operator-(const Time& other) const {
        return Time(this->toSeconds() - other.toSeconds());
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << std::setfill('0') << std::setw(2) << time.hours << ":"
            << std::setfill('0') << std::setw(2) << time.minutes << ":"
            << std::setfill('0') << std::setw(2) << time.seconds;
        return os;
    }
};

int main() {
    Time t1(23, 59, 30);
    Time t2("00:00:30");

    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;

    if (t1 > t2) {
        std::cout << "t1 > t2" << std::endl;
    }
    else if (t1 == t2) {
        std::cout << "t1 == t2" << std::endl;
    }
    else {
        std::cout << "t1 < t2" << std::endl;
    }

    Time t3 = t1 + 60;
    std::cout << t3 << std::endl;

    Time t4 = t1 - 30;
    std::cout << t4 << std::endl;

    long long diff = (t1 - t2).toSeconds();
    std::cout << "Difference: " << diff << " seconds" << std::endl;

    return 0;
}