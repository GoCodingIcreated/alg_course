#include<iostream>
#include <vector>

bool comp_1(const int &a, const int &b) {
    return a < b;
}

bool comp_2(const int &a, const int &b) {
    return a > b;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }
    auto comp = comp_2;
    if (seq[0] > seq[1]) {
        comp = comp_1;
    }
    int L = 0, R = n - 1;
    while (R - L > 3) {
        int m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
        if (comp(seq[m1], seq[m2])) {
            R = m1;
        }
        else {
            L = m2;
        }
    }
    int idx_extr = L;
    for (; L <= R; ++L) {
        if (comp(seq[L], seq[idx_extr])) {
            idx_extr = L;
        }
    }
    std::cout << idx_extr << std::endl;
    return 0;
    L = 0, R = idx_extr + 1;
    while (R - L > 1) {
        int mid = L + (R - L) / 2;
        if (comp(seq[mid], k)) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    if (seq[L] == k) {
        std::cout << L << std::endl;
        return 0;
    }
    L = idx_extr, R = n;
    while (R - L > 1) {
        int mid = L + (R - L) / 2;
        if (comp(seq[mid], k)) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    std::cout << L << std::endl;
}
