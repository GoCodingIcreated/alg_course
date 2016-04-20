#include <iostream>

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long c = gcd(b, a % b, x, y);
    std::swap(x, y);
    y -= x * (a / b);
    std::cout << c << ' ' << x << ' ' << y << std::endl;
    return c;
}

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;
    long long x, y;
    long long c1 = gcd(a, b, x, y);
    //std::cout << x << ' ' << y << std::endl;
    //return 0;
    if (c == 0) {
        a /= c1, b /= c1;
        if (b < 0) {
            b = -b, a = -a;
        }
        std::cout << b << ' ' << -a << std::endl;
        return 0;
    }
    if (c % c1 != 0) {
        std::cout << "No" << std::endl;
    }
    else {
        x *= c / c1, y *= c / c1;
        b /= c1, a /= c1;
        std::cout << x << ' ' << y << ' ' << a << ' ' << b << std::endl;
        if (b < 0) {
            b = -b, a = -a;
        }
        while (x <= 0) {
            x += b, y -= a;
        }
        while (x - b > 0) {
            x -= b, y += a;
        }
        std::cout << x << ' ' << y << std::endl;
    }
    return 0;
}
