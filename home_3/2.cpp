#include <iostream>

const int MAX_EXP = 8;

int EXPS[MAX_EXP];

struct Node {
    Node *next;
    int number;
    int length;
    Node(int a) {
        number = a;
        next = NULL;
        length = 0;
        while (a > 0) {
            a /= 10;
            ++length;
        }
        number *= EXPS[MAX_EXP - length];
    }
    Node() {
        number = 0;
        next = NULL;
        length = 0;
    }
    int get(int pos) {
        if (MAX_EXP - pos > length) {
            return 10;
        }
        return number / EXPS[pos] % 10;
    }
};


// pos from MAX_EXP - 1 
int radix_sort(Node *list, Node *k, int pos) {
    if (list->next == NULL) {
        return 1;
    }
    int digit = k->get(pos);
    if (digit == 10) {
        return 1;
    }
    Node *heads[11], *tails[11];
    int cnt[11] = {0};
    for (int i = 0; i < 11; ++i) {
        heads[i] = tails[i] = NULL;
    }
    for (; list != NULL;) {
        digit = list->get(pos);
        Node *nxt = list->next;
        if (heads[digit] == NULL) {
            heads[digit] = list;
        }
        else {
            tails[digit]->next = list;
        }
        tails[digit] = list;
        tails[digit]->next = NULL;
        ++cnt[digit];
        list = nxt;
    }
    digit = k->get(pos);
    int sum = 0;
    for (int i = 0; i < digit; ++i) {
        sum += cnt[i];
    }
    sum += cnt[10];
    return sum + radix_sort(heads[digit], k, pos - 1);
}



int main() {
    EXPS[0] = 1;
    for (int i = 1; i < MAX_EXP; ++i) {
        EXPS[i] = 10 * EXPS[i - 1];
    }
    int n, k;
    std::cin >> n >> k;
    Node *head = new Node[n], *tail = head;
    *head = Node(1);
    for (int i = 1; i < n; ++i) {
        tail = tail->next = &head[i];
        *tail = Node(i + 1);
    }
    Node *K = new Node(k);
    int result = radix_sort(head, K, MAX_EXP - 1);
    std::cout << result << std::endl;
}
