#include <iostream>
#include <sstream>

struct Data {
    std::string name;
    int val;
    bool operator==(const Data &) const;
    bool operator<(const Data &) const;
    friend std::istream& operator>>(std::istream &, Data &);
    friend std::ostream& operator<<(std::ostream &, const Data &);
};


class AVL {
    struct AVLnode {
        AVLnode *left, *right;
        Data data;
        int height;
        AVLnode(const Data&);
        AVLnode *insert(AVLnode *);
        AVLnode* balance();
        void print(std::string &) const;
        AVLnode *rotate_left();
        AVLnode *rotate_right();
        int get_balance_factor() const;
        void fix();
    };
    AVLnode *root;
    void delete_nodes(AVLnode*);
public:
    AVL();
    ~AVL();
    void insert(const Data &);
    void change(const Data &);
    const Data& find(const Data &) const;
    std::string print() const;
};

class Heap {
    int capacity;
    int size;
    Data* data;
    void sift_down();
    void sift_up();
    void extand();
public:
    Heap();
    ~Heap();
    Data get_max() const;
    void pop_max();
    int add(const Data &);
    int increase_priority(const Data &);
    bool empty() const;
    void print() const;
};


bool Data::operator==(const Data &data) const {
    return name == data.name;
}
bool Data::operator<(const Data &data) const {
    return name < data.name;
}
std::istream& operator>>(std::istream &in, Data &data) {
    in >> data.name;
    in >> data.val;
    return in;
}
std::ostream& operator<<(std::ostream &out, const Data &data) {
    out << data.name << ' ' << data.val;
    return out;
}

void AVL::delete_nodes(AVLnode *node) {
    if (node == NULL) {
        return;
    }
    AVL::delete_nodes(node->left);
    AVL::delete_nodes(node->right);
    delete node;
}

AVL::AVL() {
    root = NULL;
}

AVL::~AVL() {
    delete_nodes(root);
}

AVL::AVLnode::AVLnode(const Data &data) {
    height = 1;
    right = left = NULL;
    this->data = data;
}

AVL::AVLnode* AVL::AVLnode::insert(AVLnode *node) {
    if (node->data < data) {
        left = left == NULL ? node : left->insert(node);
    }
    else {
        right = right == NULL ? node : right->insert(node);
    }
    return balance();
}

void AVL::insert(const Data &data) {
    AVLnode *new_node = new AVLnode(data);
    if (root == NULL) {
        root = new_node;
    }
    else {
        root = root->insert(new_node);
    }
}

void AVL::AVLnode::print(std::string &output) const {
    if (left != NULL) {
        left->print(output);
    }
    //std::cout << data << std::endl;
    //output += data.data + '\n';
    std::stringstream istr;
    istr << data << '\n';
    output += istr.str();
    if (right != NULL) {
        right->print(output);
    }
}

std::string AVL::print() const {
    std::string output;
    if (root != NULL) {
        root->print(output);
    }
    return output;
}

int AVL::AVLnode::get_balance_factor() const {
    int l = left == NULL ? 0 : left->height;
    int r = right == NULL ? 0 : right->height;
    return r - l;
}

void AVL::AVLnode::fix() {
    int l = left == NULL ? 0 : left->height;
    int r = right == NULL ? 0 : right->height;
    height = std::max(l, r) + 1;
}

AVL::AVLnode* AVL::AVLnode::rotate_left() {
    AVL::AVLnode *t = right;
    right = t->left;
    t->left = this;
    fix();
    t->fix();
    return t;
}

AVL::AVLnode* AVL::AVLnode::rotate_right() {
    AVL::AVLnode *t = left;
    left = t->right;
    t->right = this;
    fix();
    t->fix();
    return t;
}

AVL::AVLnode* AVL::AVLnode::balance() {
    fix();
    switch (get_balance_factor()) {
    case -2:
        if (left->get_balance_factor() > 0) {
            left = left->rotate_left();
        }
        return rotate_right();
    case 2:
        if (right->get_balance_factor() < 0) {
            right = right->rotate_right();
        }
        return rotate_left();
    default:
        return this;
    } 
}


const Data& AVL::find(const Data &data) const {
    AVLnode *current = root;
    while (current != NULL && !(current->data == data)) {
        if (data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    if (current == NULL) {
        throw 1;
    }
    return current->data;
}


void AVL::change(const Data &data) {
    const Data &d = find(data);
    const_cast<Data&>(d).val = data.val;
}

/*
int main() {
    Data data;
    AVL avl;
    Heap heap;
    while (std::cin >> data) {
        int a;
        if (0 == (a = avl.find(data).val)) {
            a = heap.add(data);
            data.val = a;
            avl.insert(data);
        }
        else {
            a = heap.increase_priority(a, data);
            data.val = a;
            avl.change(data);
        }
    }
    while (!heap.empty()) {
        std::cout << heap.get_max() << std::endl;
        heap.pop_max();
    }
}
*/
