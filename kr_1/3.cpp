#include <iostream>
#include <cstdio>
int len[30];

void gen(int n, int k, int L) {
//    printf("(%d,%d,%d)\n", n, k, L);
    if (k == 0) {
        std::cout << char('a' + n);// << std::endl;
    }
    if (n == 0) {
        return;
    }
    if (k <= len[n - 1] && std::min(len[n - 1], L - 1) - std::max(0, (k - 1)) > 0 ) {
//        printf("left:");
        gen(n - 1, std::max(0, k - 1), std::min(len[n - 1], L - 1));
    }
    if (L > len[n - 1] + 1 && (L - len[n - 1] - 1) - std::max(0, k - len[n - 1] - 1) > 0) {
//        printf("right:");
        gen(n - 1, std::max(0, k - len[n - 1] - 1), L - len[n - 1] - 1);
    }
//    printf("ret\n");
}

int main() {
    len[0] = 1;
    for (int i = 1; i < 28; ++i) {
        len[i] = 2 * len[i - 1] + 1;
    }
    int n, k, l;
    std::cin >> n >> k >> l;
    --k, --n;
    gen(n, k, l);
}
