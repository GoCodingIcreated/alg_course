#include <iostream>

#include "stack.h"

int main() {
    stack s;
    for (int i = 0; i < 50; ++i) {
        s.push(i * i);
    }
    for (int i = 0; i < 50; ++i) {
        std::cout << s.pop() << std::endl;
    }
    return 0;
}
