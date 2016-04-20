#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
struct Node {
    std::string data;
    std::vector<Node*> children;
    int R;
    Node() { R = 0; }
};

void dfs(Node *head, int level) {
    //std::cout << head->data << ' ' << level << ' ' << head->R << std::endl;
    for (int i = 0; i < head->children.size(); ++i) {
        dfs(head->children[i], level + 1);
        head->data += head->children[i]->data;
    }
    if (head->R == 1) {
        std::reverse(head->data.begin(), head->data.end());
    }
}

int main() {
    char ch;
    std::string word;
    Node *new_node;
    int state = 1;
    std::stack<Node*> st;
    while (std::cin >> ch) {
        if (ch == '(') {
            st.push(new Node());
            state = 0;
        }
        else if (ch == ',') {
        
        }
        else if (ch == ')') {
            state = 1;
            new_node = st.top();
            st.pop();
            if (!st.empty()) {
                st.top()->children.push_back(new_node);
            }
        }
        else if (ch == 'R' && state == 1) {
              new_node->R = 1;
        }
        else {
            st.top()->data += ch;
        }
    }
    dfs(new_node, 0);
    std::cout << new_node->data << std::endl;
}
