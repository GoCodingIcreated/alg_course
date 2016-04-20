#include <iostream>

template <class T>
class Heap {
    T *elems;
    int capacity;
    int size;
    void heap_up(int idx) {
        while (idx > 1 && elems[idx]->period < elems[idx / 2]->period) {
            std::swap(elems[idx], elems[idx / 2]);
            idx /= 2;
        }
    }
    void heap_down(int idx) {
        while (2 * idx < size) {
            int idx_min = 2 * idx;
            if (2 * idx + 1 < size && elems[idx_min + 1]->period < elems[idx_min]->period) {
                idx_min++;
            }
            if (elems[idx_min]->period < elems[idx]->period) {
                std::swap(elems[idx_min], elems[idx]);
                idx = idx_min;
            }
            else {
                break;
            }
        }
    }
public:
    Heap() {
        size = 1;
        capacity = 5;
        elems = new T[capacity];
    }
    void insert(const T &new_elem) {
        if (size == capacity) {
            capacity <<= 1;
            T *tmp = new T[capacity];
            std::copy(elems, elems + size, tmp);
            delete[] elems;
            elems = tmp;
        }
        elems[size] = new_elem;
        ++size;
        heap_up(size - 1);
    }
    T fetch_min() const {
        return elems[1];
    }
    T extract_min() {
        std::swap(elems[1], elems[--size]);
        heap_down(1); 
        return elems[size];
    }
    int get_size() const {
        return size;
    }
    void print() const {
        for (int i = 1; i < size; ++i) {
            std::cout << elems[i]->period << ' ';
        }
        std::cout << std::endl;
    }
};


struct Node {
    Node *left, *right;
    long long period;
    Node(int p) : left(NULL), right(NULL), period(p) {}
};


long long dfs_heap(Node *root, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        long long result = root->period * level;
        delete root;
        return result;    
    }
    long long result = dfs_heap(root->left, level + 1) + dfs_heap(root->right, level + 1);
    delete root;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    Heap<Node*> heap;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        heap.insert(new Node(x));
    }
    //heap.print();
    for (int i = 0; i < n - 1; ++i) {
        Node *tmp_1 = heap.extract_min();
        Node *tmp_2 = heap.extract_min();
        Node *new_node = new Node(tmp_1->period + tmp_2->period);
        new_node->left = tmp_1;
        new_node->right = tmp_2;
        heap.insert(new_node);
    }
    std::cout << dfs_heap(heap.fetch_min(), 0) << std::endl;
}
