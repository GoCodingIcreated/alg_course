#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstring>
const unsigned digit_place = 0xFF;
const unsigned digit_place_count = 4;

unsigned* radix_sort(unsigned *a, int n) {
    unsigned *b = new unsigned[n];
    //unsigned char *p = new unsigned char[n];
    int c[digit_place + 1];
    for (int k = 0; k < digit_place_count; ++k) {
        for (int i = 0; i < digit_place + 1; ++i) {
            c[i] = 0;
        }
        unsigned char d;
        for (int i = 0; i < n; ++i) {
            d = *((unsigned char*)&a[i] + k);
            ++c[d];
        }
        int count = 0, tmp;
        for (int i = 0; i < digit_place + 1; ++i) {
            tmp = c[i];
            c[i] = count;
            count += tmp;
        }
        for (int i = 0; i < n; ++i) { 
            d = *((unsigned char*)&a[i] + k);
            b[c[d]] = a[i];
            ++c[d];
        }
        std::swap(a, b);
    }
    return a;
}

int main() {
    unsigned N, K, M, L;
    std::cin >> N >> K >> M >> L;
    unsigned *a = new unsigned[N];
    a[0] = K;
    for (unsigned i = 1; i < N; ++i) {
        a[i] = (unsigned)((a[i - 1] * (unsigned long long) M) & 0xFFFFFFFFU) % L;
    }
    a = radix_sort(a, N);
    /*for (int i = 0; i < N; ++i) {
        std::cout << a[i] << ' ' ;
    }
    std::cout << std::endl;*/
    unsigned long long sum = 0;
    for (int i = 0; i < N; i += 2) {
        sum = (sum + a[i]) % L;
    }
    std::cout << sum << std::endl;
}
