#include <iostream>

#include "stack.h"

int main() {
    stack st;
    int x = 0;
    std::cin >> x;
    while (x != -1) {
        if (x == 1) {
            st.push(x);
        }
        else {
            if (st.empty()) {
                st.push(x);
                std::cout << "NO" << std::endl;
                break;
            }
            st.pop();
        }
        std::cin >> x;
    }
    if (st.empty()) {
        std::cout << "YES" << std::endl;
    }
    return 0;
}
