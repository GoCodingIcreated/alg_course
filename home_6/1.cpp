#include <iostream>
#include <vector>
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n + 1, 0);
    vec[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0 && i - j <= m; --j) {
            vec[i] += vec[j];
        }
    }
    std::cout << vec[n] << std::endl;
}
