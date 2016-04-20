#include <iostream>
#include <cmath>
const int MAX_N = 1000;
long long a[MAX_N][MAX_N];


int main() {
    int n;
    long long x;
    std::cin >> n;
    if (n >= MAX_N) {
        return 1;
    }
    for (int i = n - 1; i >= 0; --i)  {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }
    std::cin >> x;
    int L = -1, R = n;
    while (R - L > 1) {
        int mid = abs(L + R) / 2 + abs(L + R) % 2;
        if (a[mid][mid] < x) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    if (R == n || R == -1) {
        std::cout << "no\n";
        return 0;
    }
    for (int i = 0; i <= R; ++i) {
        if (a[i][R] == x || a[R][i] == x) {
            std::cout << "yes\n";
            return 0;
        }
    }
    std::cout << "no\n";
    return 0;
}
