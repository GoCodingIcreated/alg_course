#include <iostream>

int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int c = gcd(b, a % b, x, y);
    std::swap(x, y);
    y -= x * (a / b);
    return c;
}

int main() {
    //int a, b, c;
    //std::cin >> a >> b >> c;
    for (int a = -100; a <= 100; ++a) {
        for (int b = -100; b <= 100; ++b) {
            for (int c = -100; c <= 100; ++c) {
                std::cout << a << ' ' << b << ' ' << c << std::endl;
                int x, y;
                int c1 = gcd(a, b, x, y);
                if (c == 0) {
                    a /= c1, b /= c1;
                    if (b < 0) {
                        b = -b, a = -a;
                        }
                    std::cout << b << ' ' << -a << std::endl;
                }
                if (c % c1 != 0) {
                    std::cout << "No" << std::endl;
                }
                else {
                    x *= c / c1, y *= c / c1;
                    if (b < 0) b = -b, a = -a;
                    while (x <= 0) {
                        x += b, y -= a;
                    }
                    while (x - b > 0) {
                        x -= b, y += a;
                    }
                    std::cout << x << ' ' << y << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
    
    return 0;
}
