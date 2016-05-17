#include <iostream>
#include <string>

const int MAX_N = 2000;
long long N[MAX_N + 1][MAX_N + 1];

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    for (size_t i = 0; i <= MAX_N; ++i) {
        N[i][0] = i;
        N[0][i] = i;
    }
    if (s1.size() > MAX_N || s2.size() > MAX_N) {
        return 1;
    }
    for (size_t i = 1; i <= s1.size(); ++i) {
        for (size_t j = 1; j <= s2.size(); ++j) {
            N[i][j] = std::min(std::min(N[i][j - 1] + 1, N[i - 1][j] + 1), N[i - 1][j - 1] + ((s1[i - 1] != s2[j - 1]) ? 1 : 0));
        }
    }
    std::cout << N[s1.size()][s2.size()] << std::endl;
    /*for (size_t i = 0; i <= s1.size(); ++i) {
        for (size_t j = 0; j <= s2.size(); ++j) {
            std::cout << N[i][j] << ' ' ;
        }
        std::cout << std::endl;
    }*/
}
