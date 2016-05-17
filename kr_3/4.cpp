#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 1000000;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> lens(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lens[i];
    }
    std::sort(lens.begin(), lens.end());
    std::vector<std::pair<int, int> > din(n, std::make_pair(0, 0));
    din[1].first = lens[1] - lens[0];
    din[1].second = INF;
    for (int i = 2; i < n - 1; ++i) {
        din[i].first = std::min(din[i - 1].first, din[i - 1].second) + lens[i] - lens[i - 1];
        din[i].second = din[i - 1].first;
    }
    /*for (int i = 0; i < n - 1; ++i) {
        std::cout << din[i].first << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n - 1; ++i) {
        std::cout << din[i].second << ' ';
    }
    std::cout << std::endl;
    */
    std::cout << std::min(din[n - 2].first, din[n - 2].second) + lens[n - 1] - lens[n - 2] << std::endl;
}
