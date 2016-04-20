#include <iostream>

#include "stack.h"

#define LEFT_R 1
#define RIGHT_R 0
#define LEFT_S 3
#define RIGHT_S 2

bool is_correct(int left, int right) {
    return left == LEFT_R && right == RIGHT_R || left == LEFT_S && right == RIGHT_S;
}

int main() {
    stack st;
    int x = 0;
    std::cin >> x;
    bool is_good = true;
    while (is_good && x != -1) {
        if (x == LEFT_R || x == LEFT_S) {
            st.push(x);
        }
        else {
            if (st.empty()) {
                is_good = false;
            }
            else {    
                int y = st.pop();
                if (!is_correct(y, x)) {
                    is_good = false;
                }
            }
        }
        std::cin >> x;
    }
    if (!st.empty()) {
        is_good = false;
    }
    if (is_good) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
