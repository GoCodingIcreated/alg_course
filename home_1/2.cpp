#include <iostream>

int main() {
    int N;
    std::cin >> N;
    long long max[2];
    std::cin >> max[0];
    if (N == 1) {
        std::cout << max[0];
        return 0;
    }
    std::cin >> max[1];
    if (max[0] < max[1]) {
        std::swap(max[0], max[1]);
    }
    long long x;
    for (int i = 2; i < N; ++i) {
        std::cin >> x;
        if (x >= max[0]) {
            max[1] = max[0];
            max[0] = x;
        }
        else {
            max[1] = x > max[1] ? x : max[1];
        }
    }
    std::cout << max[1] << std::endl;
}
