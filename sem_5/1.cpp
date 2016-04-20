#include <iostream>

template <class T>
class Heap {
    T *elems;
    int capacity;
    int size;
    void heap_up(int idx) {
        while (idx > 1 && elems[idx] < elems[idx / 2]) {
            std::swap(elems[idx], elems[idx / 2]);
            idx /= 2;
        }
    }
    void heap_down(int idx) {
        while (2 * idx < size) {
            int idx_min = 2 * idx;
            if (2 * idx + 1 < size && elems[idx_min + 1] < elems[idx_min]) {
                idx_min++;
            }
            if (elems[idx_min] < elems[idx]) {
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
    T fetchMin() const {
        return elems[1];
    }
    T extractMin() {
        std::swap(elems[1], elems[size - 1]);
        heap_down(1); 
        return elems[--size];
    }
    int get_size() const {
        return size;
    }
    void print() const {
        for (int i = 1; i < size; ++i) {
            std::cout << elems[i] << ' ';
        }
        std::cout << std::endl;
    }
    void remove(const T &key) {
        int idx = 0;
        for (int i = 1; i < size; ++i) {
            if (key == elems[i]) {
                idx = i;
                break;
            }
        }
        if (idx == 0) {
            return;
        }
        std::swap(elems[idx], elems[size - 1]);
        --size;
        if (elems[idx] > elems[size]) {
            heap_down(idx);    
        }
        else {
            heap_up(idx);
        }
    }
    void increase_priority(const T& key_old, const T &key_new) {
        int idx = 0;
        for (int i = 1; i < size; ++i) {
            if (key_old == elems[i]) {
                idx = i;
                break;
            }
        }
        if (idx == 0) {
            return;
        }
        elems[idx] = key_new;
        heap_up(idx);
        heap_down(idx);
    }
};


int main() {
    Heap<int> my_heap;
    for (int i = 20; i > 0; --i) {
        my_heap.insert(i);
    }
    my_heap.remove(10);
    my_heap.increase_priority(11, 30);
    my_heap.print();
}
