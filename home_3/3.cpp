#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int> > sequence(n);
    for (auto it = sequence.begin(); it != sequence.end(); ++it) {
        std::cin >> it->first;
        it->second = it - sequence.begin() + 1;
    }
    std::sort(sequence.begin(), sequence.end());
    auto min_1 = sequence.begin(), min_2 = sequence.begin() + 1;
    for (auto it = sequence.begin(); it != sequence.end() - 1; ++it) {
        if ((it + 1)->first - it->first < min_2->first - min_1->first) {
            min_1 = it;
            min_2 = it + 1;
        }
    }
    std::cout << min_2->first - min_1->first << std::endl;
    std::cout << std::min(min_1->second, min_2->second) << ' ';
    std::cout << std::max(min_1->second, min_2->second) << std::endl;
}
