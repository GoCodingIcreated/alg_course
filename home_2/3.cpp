#include <iostream>
#include <vector>
int main() {
    int size_1, size_2;
    std::cin >> size_1 >> size_2;
    std::vector<long long> v1(size_1);
    std::vector<long long> v2(size_2);
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        std::cin >> *it;
    }
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        std::cin >> *it;
    }
    long long count = 0;
    /*auto it1 = v1.begin();
    auto it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end()) {
        if (*it1 == *it2) {
            ++it1, ++it2, ++count;
        }
        else if (*it1 < *it2) {
            ++it1;
        }
        else {
            ++it2;
        }
    }*/
    std::vector<bool> used(size_2, false);
    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            if (v1[i] == v2[j] && !used[j]) {
                used[j] = true;
                count++;
                break;
            }
        }
    }
    std::cout << count << std::endl;
}
