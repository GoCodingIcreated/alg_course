#include <iostream>
#include <list>

int main() {
    std::list<int> List {1, 2, 3, 4, 5};
    std::list<int> List2 {9, 10, 11};
    auto it = List.begin();
    std::advance(it, 1);
    List2.splice(List2.begin(), List, it);
    for (auto i : List2) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    for (auto i : List) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
