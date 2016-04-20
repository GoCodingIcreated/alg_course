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
    else if (root->op == '/') {
        return calc_tree(root->left) / calc_tree(root->right);
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


void parse_expr(std::stack<Node*> &numb, std::stack<Node*> &oper) {
    char ch;
    double number;
    while (std::cin >> ch) {
        if (ch >= '0' && ch <= '9') {
            std::cin.putback(ch);
            std::cin >> number;
            numb.push(new Node(number));
        }
        else if (ch == '+' || ch == '-') {
            Node *r = oper.top();
            while (r->op == '+' || r->op == '-' || r->op == '*' || r->op == '/') {
                r->right = numb.top();
                numb.pop();
                r->left = numb.top();
                numb.pop();
                numb.push(r);

                oper.pop();
                r = oper.top();
            }
            oper.push(new Node(ch));
        }
        else if (ch == '*' || ch == '/') {
            Node *r = oper.top();
            while (r->op == '*' || r->op == '/') {
                r->right = numb.top();
                numb.pop();
                r->left = numb.top();
                numb.pop();
                numb.push(r);
                
                oper.pop();
                r = oper.top();
            }
            oper.push(new Node(ch));
        }
        else if (ch == ')') {
            Node *r = oper.top();
            while (r->op != '(') {
                r->right  = numb.top();
                numb.pop();
                r->left = numb.top();
                numb.pop();
                numb.push(r);
                
                oper.pop();
                r = oper.top();
            }
            return;
        }
        else if (ch == '(') {
            oper.push(new Node(ch));
            parse_expr(numb, oper);
            if (oper.top()->op != '(') {
                throw std::string("( error");
            }
            delete oper.top();
            oper.pop();
        }
    }
    Node *r = oper.top();
    while (r->op != '(') {
        r->right = numb.top();
        numb.pop();
        r->left = numb.top();
        numb.pop();
        numb.push(r);

        oper.pop();
        r = oper.top();
    }
}

int main() {
    Node *root = NULL;
    std::stack<Node*> numb, op;
    
    op.push(new Node('('));
    
    parse_expr(numb, op);

    root = numb.top();
    delete op.top();
    op.pop();
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
