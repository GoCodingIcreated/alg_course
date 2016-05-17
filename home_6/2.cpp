#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    long long bound = 1;
    for (int i = 0; i < n; ++i) {
        if (vec[i] > bound) {
            std::cout << bound << std::endl;
            return 0;
        }
        bound += vec[i];
    }
    std::cout << bound << std::endl;
}
