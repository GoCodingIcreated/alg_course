#include <iostream>

struct Node {
    Node *next;
    std::string name;
    std::string number;
    Node(std::string name, std::string number) : next(NULL), name(name), number(number) {}
};

void list_add(Node * &head, std::string &name, std::string number) {
    Node *new_node = new Node(name, number);
    if (head == NULL) {
        head = new_node;
        return;
        //return true;
    }
    for (Node *it = head; it != NULL; it = it->next) {
        if (it->name == name) {
            //return false;
            std::cout << "ERROR" << std::endl;
            return;
        }
    }
    new_node->next = head;
    head = new_node;
    //return true;
}

void list_print(Node *head, std::string &name) {
    for (; head != NULL && head->name != name; head = head->next) {}
    if (head != NULL) {
        std::cout << head->name << ' ' << head->number << std::endl;
        return;
        //return true;
    }
    std::cout << "ERROR" << std::endl;
    //return false;
}

void list_delete(Node *&head, std::string &name) {
    Node *last = head, *it;
    for (it = head; it != NULL && it->name != name; last = it, it = it->next) {}
    if (it == NULL) {
        std::cout << "ERROR" << std::endl;
        return;
    }
    last->next = it->next;
    if (it == head) {
        head = head->next;
    }
    delete it;
}

void list_edit(Node *head, std::string &name, std::string &number) {
    for (; head != NULL && head->name != name; head = head->next) {}
    if (head == NULL) {
        std::cout << "ERROR" << std::endl;
        return;
    }
    head->number = number;
}

void list_free(Node *&head) {
    for (Node *tmp; head != NULL; ) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

int main() {
    int n;
    std::cin >> n;
    Node *head = NULL;
    std::string command;
    std::string name, number;
    for (int i = 0; i < n; ++i) {
        std::cin >> command;
        if (command == "ADD") {
            std::cin >> name >> number;
            list_add(head, name, number);
        }
        else if (command == "DELETE") {
            std::cin >> name;
            list_delete(head, name);
        }
        else if (command == "PRINT") {
            std::cin >> name;
            list_print(head, name);
        }
        else if (command == "EDITPHONE") {
            std::cin >> name;
            std::cin >> number;
            list_edit(head, name, number);
        }
    }
    list_free(head);
}
