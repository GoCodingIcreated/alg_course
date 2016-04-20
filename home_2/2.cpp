#include <iostream>
#include <climits>
long long my_sqrt(long long n) {
    long long L = 0, R = 1000000100;
    long long mid;
    while (R - L > 1) {
        mid = (L + R) >> 1;
        if (mid * mid < n) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    return L;
}

int main() {
    long long n;
    std::cin >> n;
    long long sqrt_n = my_sqrt(n);
    long long count = sqrt_n + 1;
    long long x = sqrt_n;
    for (; x >= 0; --x) {
        count += my_sqrt(n - x * x);
    }
    std::cout << count << std::endl;
}
