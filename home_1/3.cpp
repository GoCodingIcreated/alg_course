#include <iostream>
int grey(int n) {
    return n ^ (n >> 1);
}
std::string binary(int num, int pos) {
    std::string str;
    str.resize(pos);
    for (int i = 0; i < pos; ++i) {
        str[pos - i - 1] = '0' + ((num >> i) & 1);
    }
    return str;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < (1 << n); ++i) {
        std::cout << binary(grey(i), n) << std::endl;
    }
}
