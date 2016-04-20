#include <iostream>
#include <cstdlib>
long long MAX_SIZE = 1000000000ll;

int main() {
    int n;
    std::cin >> n;
    //int a[n];// b[n];
    int *a = (int*)(int*)(int*)(int*)(int*)(int*)(int*)(int*)(int*)malloc(sizeof(int) * n);
    if (a == NULL) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    /*
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }*/
    int p1 = 0, p2 = 0;
    long long sum = 0;
    long long b;
    std::cin >> b;
    while (p1 < n && p2 < n) {
        if (a[p1] < b) {
            if (!((p1 + p2) & 1)) {
                sum += a[p1];
                sum %= MAX_SIZE;
            }
            ++p1;
        }
        else {
            if (!((p1 + p2) & 1)) {
                sum += b;
                sum %= MAX_SIZE;
            }
            ++p2;
            if (p2 < n) {
                std::cin >> b;
            }
        }
    }
    while (p1 < n) {
        if (!((p1 + p2) & 1)) {
            sum += a[p1];
            sum %= MAX_SIZE;
        }
        ++p1;
    }
    while (p2 < n) {
        if (!((p1 + p2) & 1)) {
            sum += b;
            sum %= MAX_SIZE;
        }
        ++p2;
        if (p2 < n) {
            std::cin >> b;
        }
    }
    free(a);
    std::cout << sum << std::endl;
}
