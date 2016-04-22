#include <iostream>
#include <vector>
struct triple {
    int x, y, r;
    triple(int x, int y, int r) : x(x), y(y), r(r) {}
};

struct Node {
    Node *next;
    std::string name;
    std::vector<triple> stations;
    Node(std::string name, triple tpl) : next(NULL), name(name) {
        stations.push_back(tpl);
    }
};

int add(Node * &head, std::string name, triple &tpl) {
    Node *last = head, *it = head;
    for (; it != NULL && it->name != name; last = it, it = it->next ) {}
    if (it != NULL) {
        it->stations.push_back(tpl);
        return 0;
    }
    else {
        Node *new_node = new Node(name, tpl);
        if (last == NULL) {
            head = new_node;
        }
        else {
            last->next = new_node;
        }
        return 1;
    }
}

bool in_range(int x, int y, triple &tpl) {
    return (tpl.x - x) * (tpl.x - x) + (tpl.y - y) * (tpl.y - y) <= tpl.r * tpl.r;
}

void print(Node *head, int x, int y) {    
    for (; head != NULL; head = head->next) {
        int count = 0;
        for (auto it = head->stations.begin(); it != head->stations.end(); ++it) {
            if (in_range(x, y, *it)) {
                ++count;
            }
        }
        std::cout << head->name << ' ' << count << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    Node *list = NULL;
    int x, y, r;
    std::string name;
    int operators = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> name;
        std::cin >> x >> y >> r;
        triple tpl(x, y, r);
        operators += add(list, name, tpl);
    }
    int xa, ya;
    std::cin >> xa >> ya;
    std::cout << operators << std::endl;
    print(list, xa, ya);
}
