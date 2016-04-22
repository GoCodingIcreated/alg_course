#include <iostream>
#include <stack>
class Operand {
    bool _is_number;
    union {
        int number;
        char symbol;
    };
public:
    Operand(int number) {
        this->number = number;
        _is_number = true;
    }
    Operand(char symbol) {
        this->symbol = symbol;
        _is_number = false;
    }
    bool is_number() const {
        return _is_number;
    }
    bool is_symbol() const {
        return !_is_number;
    }
    int get_value() const {
        return _is_number ? number : symbol;
    }
};

class Calculator {
    std::stack<Operand> st;
public:
    Calculator() {}
    void do_step(const Operand &op) {
        if (op.is_symbol() || st.top().is_symbol()) {
            st.push(op);
        }
        else {
            st.push(op);
            do {
                int x = st.top().get_value(); st.pop();
                int y = st.top().get_value(); st.pop();
                int operation = st.top().get_value(); st.pop();
                int result = 0;
                switch (operation) {
                    case '+':
                        result = y + x;
                        break;
                    case '-':
                        result = y - x;
                        break;
                    case '/':
                        result = y / x;
                        break;
                    case '*':
                        result = y * x;
                        break;
                }
                if (st.empty() || st.top().is_symbol()) {
                    st.push(Operand(result));
                    break;
                }
                st.push(Operand(result));
            }
            while(!st.empty() && st.top().is_number()); // never exit by this condition
        }
    }
    int get_result() const {
        return st.top().get_value();
    }
        
};

int main() {
    std::string token;
    Calculator calc;
    while (std::cin >> token) {
        if (token[0] >= '0' && token[0] <= '9') {
            calc.do_step(Operand(std::stoi(token)));
        }
        else {
            calc.do_step(Operand(token[0]));
        }
    }
    std::cout << calc.get_result() << std::endl;
    return 0;
}
