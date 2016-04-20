#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> st;
    for (size_t i = 0; i < str.size(); ++i) {
        if (st.empty()) {
            st.push(str[i]);
        }
        else if (st.top() == str[i]) {
            st.push(str[i]);
        }
        else {
            st.pop();
        }
    }
    if (st.empty()) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
