#include <iostream>

const int MAX_N = 150;
const int MAX_M = 30;
const int MAX_SUM = MAX_N * MAX_M;
unsigned MOD;
int M;
long long N[MAX_N + 1][MAX_SUM + 1];
bool used[MAX_N + 1][MAX_SUM + 1];
long long get_N(int n, int sum) {
    if (sum < 0 || n == 0) {
        return 0;
    }/*
    if (sum == 0) {
        return N[n][sum] = 1;
    }
    if (N[n][sum] != 0 || n == 1) {
        return N[n][sum];
    }*/
    if (used[n][sum]) {
        return N[n][sum];
    }
    used[n][sum] = true;
    return N[n][sum] = (get_N(n, sum - 1) + get_N(n - 1, sum) - get_N(n - 1, sum - M) + MOD) % MOD;
    //for (int i = sum - (M - 1); i <= sum; ++i) {
    //    N[n][sum] = (N[n][sum] + get_N(n - 1, i)) % MOD;
    //}
    //return N[n][sum];
}


int main() {
    int n;
    std::cin >> n >> M >> MOD;
    for (int i = 0; i < M; ++i) {
        N[1][i] = 1;
        used[1][i] = true;
    }
    for (int i = 0; i <= MAX_SUM; ++i) {
        used[1][i] = true;
    }
    for (int i = 1; i <= n; ++i) {
        N[i][0] = 1;
        used[i][0] = true;
    }
    /*for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i * (M - 1); ++j) {
            N[i][j] = get_N(i, j - 1) + get_N(i - 1, j) - get_N(i - 1, j - M)
        }
    }*/
    std::cout << get_N(n, n / 2 * (M - 1)) << std::endl;
    //for (int i = 1; i <= n ;++i) {
    //    for (int j = 0; j <= n / 2 * (M - 1); ++j) {
    //        std::cout << N[i][j] << ' ';
    //    }
    //    std::cout << std::endl;
    //}
}
