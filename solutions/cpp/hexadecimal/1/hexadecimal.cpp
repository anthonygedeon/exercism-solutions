#include "hexadecimal.h"
#include <cmath>

namespace hexadecimal {

int hex(char n) {
    switch (tolower(n)) {
    case 'a':
        return 10;
    case 'b':
        return 11;
    case 'c':
        return 12;
    case 'd':
        return 13;
    case 'e':
        return 14;
    case 'f':
        return 15;
    }
    return n;
}

int convert(std::string number) {
    int result{0};
    int power = number.size() - 1;
    for (auto &n : number) {
        if (n >= '0' && n <= '9') {
            result += (hex(n) - '0') * std::pow(16, power);
            power--;
        } else if (tolower(n) >= 'a' && tolower(n) <= 'f') {
            result += hex(n) * std::pow(16, power);
            power--;
        } else {
            return 0;
        }
    }
    return result;
}
} // namespace hexadecimal
