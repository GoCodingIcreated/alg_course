#include <iostream>

class stack {
    enum { SIZE = 100 };
    int body[SIZE];
    int head;
public:
    stack() {
        head = 0;
    }
    ~stack() { }
    void push(int val) {
        body[head++] = val;
    }
    int top() {
        return body[head - 1];
    }
    int pop() {
        return body[--head];
    }
    bool empty() {
        return head == 0;
    }
};

int main() {
    char c;
    stack st;
    while (std::cin >> c) {
        if (st.empty()) {
            st.push(c);
        }
        else {
            if (st.top() != c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
    }
    if (st.empty()) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
