#include <iostream>
#include <vector>

int calc_wires(std::vector<int> &wires, int m) {
    int result = 0;
    for (auto it = wires.begin(); it != wires.end(); ++it) {
        result += *it / m;
    }
    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> wires(n);
    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> wires[i];
        if (wires[i] > max_length) {
            max_length = wires[i];
        }
    }
    int L = 0, R = max_length + 1;
    while (R - L > 1) {
        int mid = L + (R - L) / 2;
        int current_wires = calc_wires(wires, mid);
        if (current_wires >= k) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    std::cout << L << std::endl;
}
