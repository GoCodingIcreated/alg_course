#include <iostream>
#include <vector>

long long MAX_SIZE = 1000000000ll;

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> brekets(n + 1);
    brekets[0] = 1;
    for (int i = 1; i <= n; ++i) {
        brekets[i] = 0;
        for (int j = 0; j < i; ++j) {
            brekets[i] += brekets[j] * brekets[i - j - 1] % MAX_SIZE;
        }
        brekets[i] %= MAX_SIZE;
    }
    std::cout << brekets[n] << std::endl;
}
