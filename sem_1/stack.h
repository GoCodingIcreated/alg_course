class stack {
    enum { SIZE = 100 };
    int body[SIZE];
    int head;
public:
    stack() {
        head = 0;
    }
    ~stack() { }
    void push(int val) {
        body[head++] = val;
    }
    int pop() {
        return body[--head];
    }
    bool empty() {
        return head == 0;
    }
};
