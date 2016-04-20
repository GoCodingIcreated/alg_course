#include <iostream>
#include <stdio.h>

const unsigned digit_place = 0xFF;

const int MAX_N = 56 * 1000 * 1000;

unsigned arr_1[MAX_N], arr_2[MAX_N];
int counts[digit_place + 1][4];
//unsigned char byte_1[MAX_N][4], byte_2[MAX_N][4];
void radix_sort(unsigned a[MAX_N], unsigned b[MAX_N], int N, unsigned shift, int idx) {
    unsigned mask = 0xFF, tmp;
    for (int i = 1; i < digit_place + 1; ++i) {
        counts[i][idx] += counts[i - 1][idx];
    }
    for (int i = N - 1; i >= 0; --i) {
        b[--counts[(a[i] >> shift) & mask][idx]] = a[i];
    }
}
int main() {
    unsigned K, L;
    int N;
    unsigned long long M;
    //std::cin >> N >> K >> M >> L;
    scanf("%d%u%llu%u", &N, &K, &M, &L);
    unsigned tmp;
    arr_1[0] = tmp = K;
    for (int j = 0; j < 4; ++j) {
        ++counts[(unsigned char) tmp][j];
        tmp >>= 8;
    }
    for (int i = 1; i < N; ++i) {
        arr_1[i] = tmp = (unsigned)((arr_1[i - 1] * M) & 0xFFFFFFFFU) % L;
        for (int j = 0; j < 4; ++j) {
            ++counts[(unsigned char)tmp][j];
            tmp >>= 8;
        }
    }
    /*for (int i = 0; i < N; ++i) {
        std::cout << arr_1[i] << ' ' ;
    }*/
    radix_sort(arr_1, arr_2, N, 0, 0);
    radix_sort(arr_2, arr_1, N, 8, 1);
    radix_sort(arr_1, arr_2, N, 16, 2);
    radix_sort(arr_2, arr_1, N, 24, 3);
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
