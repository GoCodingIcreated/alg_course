#include <iostream>
#include <sstream>

struct HeapData;
class Heap;

struct AVLData {
    std::string name;
    int heap_pos;
    bool operator<(const AVLData &) const;
    bool operator==(const AVLData &) const;
    friend std::istream& operator>>(std::istream &, AVLData &);
    friend std::ostream& operator<<(std::ostream &, const AVLData &);
};

class AVL {
    friend class HeapData;
    struct AVLnode {
        AVLnode *left, *right;
        AVLData data;
        int height;
        AVLnode(const AVLData&);
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
    void insert(Heap &, HeapData &, const AVLData &);
    void change(const AVLData &);
    const AVLData& find(const AVLData &) const;
    std::string print() const;
};

struct HeapData {
    int priority;
    int time;
    AVL::AVLnode* node;
    HeapData();
    ~HeapData();
    bool operator<(const HeapData &) const;
    bool operator==(const HeapData &) const;
};

class Heap {
    int capacity;
    int size;
    HeapData* data;
    void sift_down(int);
    void sift_up(int);
    void extand();
    static int time;
public:
    Heap();
    ~Heap();
    HeapData get_max() const;
    void pop_max();
    void add(HeapData &);
    void increase_priority(int,HeapData &);
    bool empty() const;
    std::string print() const;
};
int Heap::time = 0;

bool AVLData::operator==(const AVLData &data) const {
    return name == data.name;
}
bool AVLData::operator<(const AVLData &data) const {
    return name < data.name;
}
std::istream& operator>>(std::istream &in, AVLData &data) {
    in >> data.name;
    in >> data.heap_pos;
    return in;
}
std::ostream& operator<<(std::ostream &out, const AVLData &data) {
    out << data.name << ' ' << data.heap_pos;
    return out;
}

HeapData::HeapData() {
    node = NULL;
    priority = 0;
}
HeapData::~HeapData() {
    node = NULL;
    priority = 0;
}
bool HeapData::operator<(const HeapData &d) const {
    if (priority == d.priority) {
        return time < d.time;
    }
    return priority < d.priority;
}

bool HeapData::operator==(const HeapData &d) const {
    return priority == d.priority;
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

AVL::AVLnode::AVLnode(const AVLData &data) {
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

void AVL::insert(Heap &heap, HeapData &heap_data, const AVLData &data) {
    AVLnode *new_node = new AVLnode(data);
    if (root == NULL) {
        root = new_node;
    }
    else {
        root = root->insert(new_node);
    }
    heap_data.node = new_node;
    heap.add(heap_data);
}

void AVL::AVLnode::print(std::string &output) const {
    if (left != NULL) {
        left->print(output);
    }
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


const AVLData& AVL::find(const AVLData &data) const {
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


void AVL::change(const AVLData &data) {
    const AVLData &d = find(data);
    const_cast<AVLData&>(d).heap_pos = data.heap_pos;
}

void Heap::extand() {
    HeapData *new_data = new HeapData[capacity << 1];
    std::copy(data, data + capacity, new_data);
    delete[] data;
    data = new_data;
    capacity <<= 1;
}

void Heap::sift_up(int idx) {
    while (idx > 1 && data[idx / 2] < data[idx]) {
        std::swap(data[idx / 2], data[idx]);
        if (data[idx].node != NULL) {
            data[idx].node->data.heap_pos = idx;
        }
        if (data[idx / 2].node != NULL) {
            data[idx / 2].node->data.heap_pos = idx / 2;
        }
        idx /= 2;
    }
}

void Heap::sift_down(int idx) {
    while (2 * idx < size) {
        int idx_max = 2 * idx;
        if (2 * idx + 1 < size && data[2 * idx] < data[2 * idx + 1]) {
            idx_max = 2 * idx + 1;
        }
        if (data[idx] < data[idx_max]) {
            std::swap(data[idx], data[idx_max]);
            if (data[idx].node != NULL) {
                data[idx].node->data.heap_pos = idx;
            }
            if (data[idx_max].node != NULL) {
                data[idx_max].node->data.heap_pos = idx_max;
            }
            idx = idx_max;
        }
        else {
            break;
        }
    }
}
Heap::Heap() {
    capacity = 5;
    size = 1;
    data = new HeapData[capacity];
}

Heap::~Heap() {
    delete[] data;
}

HeapData Heap::get_max() const {
    return data[1];
}
void Heap::pop_max() {
    std::swap(data[1], data[size - 1]);
    --size;
    sift_down(1);
}
void Heap::add(HeapData &d) {
    if (size == capacity) {
        extand();
    }
    d.time = --time;
    if (d.node != NULL) {
        d.node->data.heap_pos = size;
    }
    data[size++] = d;
    sift_up(size - 1);
}
void Heap::increase_priority(int x, HeapData &d) {
    d.time = 0;
    if (data[x] < d) {
        data[x].priority = d.priority;
        data[x].time = --time;
    }
    sift_up(x);
}
bool Heap::empty() const {
    return size == 1;
}
std::string Heap::print() const {
    std::string out;
    for (int i = 1; i < size; ++i) {
        std::stringstream ss;
        //ss << data[i] << '\n';
        out += ss.str();
    }
    return out;
}


//int main() {
void main_function(std::istream &in, std::ostream &out) {
    std::string name;
    int val;
    AVL avl;
    Heap heap;
    int m, n;
    //std::cin >> m >> n;
    in >> m >> n;
    while (/*std::cin >> name >> val*/ in >> name >> val) {
        AVLData avl_data;
        avl_data.name = name;
        avl_data.heap_pos = 0;
        try {
            HeapData heap_data;
            heap_data.priority = val;
            heap.increase_priority(avl.find(avl_data).heap_pos, heap_data);
        }
        catch (int) {
            HeapData heap_data;
            heap_data.priority = val;
            avl.insert(heap, heap_data, avl_data);
        }
    }
    while (!heap.empty()) {
        HeapData heap_data = heap.get_max();
        heap.pop_max();
        //std::cout << heap_data.node->data.name << ' ' << heap_data.priority << std::endl;
        out << heap_data.node->data.name << std::endl;
    }
}

int main() {
    main_function(std::cin, std::cout);
}
