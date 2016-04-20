//#include <iostream>
#include <stdio.h>

const unsigned digit_place = 0xFF;

const int MAX_N = 56 * 1000 * 1000;

unsigned arr_1[MAX_N], arr_2[MAX_N];

void radix_sort(unsigned a[MAX_N], unsigned b[MAX_N], int N, unsigned shift) {
    unsigned mask = 0xFF, tmp;
    int counts[digit_place + 1] = {0};
    for (int i = 0; i < N; ++i) {
        ++counts[(a[i] >> shift) & digit_place];
    }
    for (int i = 1; i < digit_place + 1; ++i) {
        counts[i] += counts[i - 1];
    }
    for (int i = N - 1; i >= 0; --i) {
        b[--counts[(a[i] >> shift) & digit_place]] = a[i];
    }
}
int main() {
    unsigned K, L;
    int N;
    unsigned long long M;
    //std::cin >> N >> K >> M >> L;
    scanf("%d%u%lld%u", &N, &K, &M, &L);
    arr_1[0] = K;
    for (int i = 1; i < N; ++i) {
        arr_1[i] = (unsigned)((arr_1[i - 1] * M) & 0xFFFFFFFFU) % L;
    }
    /*for (int i = 0; i < N; ++i) {
        std::cout << arr_1[i] << ' ' ;
    }*/
    radix_sort(arr_1, arr_2, N, 0);
    radix_sort(arr_2, arr_1, N, 8);
    radix_sort(arr_1, arr_2, N, 16);
    radix_sort(arr_2, arr_1, N, 24);
    /*for (int i = 0; i < N; ++i) {
        std::cout << arr_1[i] << ' ' ;
    }
    std::cout << std::endl;*/
    unsigned sum = 0;
    for (int i = 0; i < N; i += 2) {
        sum = (sum + arr_1[i]) % L;
    }
    //std::cout << sum << std::endl;
    printf("%u\n", sum);
}
