#include <iostream>
#include <cstdio>
int main() {
    int n;
    std::cin >> n;
    long long max15_1 = 0, max15_2 = 0,  max5 = 0, max3 = 0, maxother = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        //std::cin >> x;
        scanf("%lld", &x);
        if (x % 15 == 0) {
            if (x >= max15_1) {
                max15_2 = max15_1;
                max15_1 = x;
            }
            else if (x > max15_2) {
                max15_2 = x;
            }
        }
        else if (x % 5 == 0) {
            max5 = max5 > x ? max5 : x;
        }
        else if (x % 3 == 0) {
            max3 = max3 > x ? max3 : x;
        }
        else if (x > maxother) {
            maxother = x;
        }
    }
    long long result = 0;
    result = std::max(result, max15_1 * maxother);
    result = std::max(result, max15_1 * max15_2);
    result = std::max(result, max15_1 * max3);
    result = std::max(result, max15_1 * max5);
    result = std::max(result, max3 * max5);
    std::cout << result << std::endl;
}
