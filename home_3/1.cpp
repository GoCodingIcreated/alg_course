#include <iostream>
#include <vector>
#include <algorithm>


bool my_cmp(const std::pair<int, char> &a, const std::pair<int, char> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main() {
    char ch;
    std::vector<std::pair<int, char> > alphabet;
    alphabet.resize(26);
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
        it->first = 0;
        it->second = (it - alphabet.begin()) + 'A';
    }
    while (std::cin.get(ch)) {
        ++alphabet[ch - 'A'].first;
    }
    std::sort(alphabet.begin(), alphabet.end(), my_cmp);
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
        if (it->first == 0) {
            break;
        }
        std::cout << it->second << ' ' << it->first << std::endl;
    }
}
