#include <iostream>
#include <stack>
struct Node {
    Node *left, *right;
    double val;
    char op;
    Node(double v) {
        val = v;
        op = 0;
        left = right = NULL;
    }
    Node(char op) : op(op) {
        val = 0;
        left = right = NULL;
    }
};

double calc_tree(Node *root) {
    if (root == NULL) {
        return 0; // error
    }
    if (root->op == 0) {
        return root->val;
    }
    else if (root->op == '+') {
        return calc_tree(root->left) + calc_tree(root->right);
    }
    else if (root->op == '-') {
        return calc_tree(root->left) - calc_tree(root->right);
    }
    else if (root->op == '*') {
        return calc_tree(root->left) * calc_tree(root->right);
    }
    return 0; // error
}

void free_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}


int main() {
    char ch;
    double number;
    Node *root = NULL;
    std::stack<Node*> st;
    while (std::cin >> ch) {
        if (ch >= '0' && ch <= '9') {
            std::cin.putback(ch);
            std::cin >> number;
            st.push(new Node(number));
        }
        else {
            Node *r = new Node(ch);
            r->right = st.top();
            st.pop();
            r->left = st.top();
            st.pop();
            st.push(r);
        }
    }
    root = st.top();
    st.pop();
    std::cout << calc_tree(root) << std::endl;
    free_tree(root);
    /*
    Node *root = new Node('+');
    root->left = new Node(5.0);
    root->right = new Node('-');
    root->right->left = new Node(15.0);
    root->right->right = new Node('*');
    root->right->right->left = new Node(4.0);
    root->right->right->right = new Node(5.0);
    std::cout << calc_tree(root) << std::endl;*/
    //free_tree(root);
}
