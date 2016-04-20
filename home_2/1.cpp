#include <iostream>
#include <vector>

const int MIN_DISTANCE = 8;

void move(std::vector<int> &v, int new_elem) {
    if (v[0] < v[1])
        std::swap(v[0], v[1]);
    v.push_back(new_elem);
    for (auto it = v.begin() + 1; it != v.end(); ++it) {
        *it = *(it + 1);
    }
    v.pop_back();
}
int get_max(std::vector<int> &v, int new_elem) {
    return v[0] * new_elem;
}
void print(std::vector<int> &v) {
        for (auto i : v) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
}
int main() {
    std::vector<int> maxs;
    for (int i = 0; i < MIN_DISTANCE; ++i) {
        maxs.push_back(0);
    }
    int current = 0;
    std::cin >> current;
    int max = 0;
    while (current >= 0) {
        int new_max = get_max(maxs, current);
        max = max > new_max ? max : new_max;
        move(maxs, current);
        std::cin >> current;
    }
    std::cout << max << std::endl;
}
