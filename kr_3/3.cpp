#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<long long> > din;
    int n, k;
    std::cin >> n >> k;
    din.assign(n, std::vector<long long>(k, 0));
    for (int i = 1; i < k; ++i) {
        din[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        long long sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += din[i - 1][j];
        }
        for (int j = 1; j < k; ++j) {
            din[i][j] = sum;
        }
        din[i][0] = sum - din[i - 1][0];
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += din[n - 1][i];
    }
    std::cout << ans << std::endl;
}
