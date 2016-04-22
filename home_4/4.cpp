#include <iostream>
#include <stack>


int calc_node(bool was_black) {
    char ch, color;
    std::cin >> ch;
    std::cin >> color;
    if (color == 'b') {
        was_black = true;
    }
    //st.push(color);
    std::cin >> ch;
    if (ch == ')') {
        return color == 'w' && was_black ? 1 : 0;
    }
    int sum = 0;
    while (ch != ')') {
        sum += calc_node(was_black);
        std::cin >> ch;
    }
    //st.pop();
    return sum + (color == 'w' && was_black ? 1 : 0);
}

int main() {
    int result = calc_node(false);
    std::cout << result << std::endl;
}
