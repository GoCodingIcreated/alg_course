#include <iostream>
#include <vector>
#include <algorithm>
struct Record {
    std::string name;
    std::vector<int> fields;
};

int perm[10];
int k;

bool cmp(const Record &a, const Record &b) {
    for (int i = 0; i < k; ++i) {
        if (a.fields[perm[i]] != b.fields[perm[i]]) {
            return a.fields[perm[i]] > b.fields[perm[i]];
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> perm[i];
        --perm[i];
    }
    std::vector<Record> records(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> records[i].name;
        records[i].fields.resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> records[i].fields[j];
        }
    }
    std::sort(records.begin(), records.end(), cmp);
    for (int i = 0; i < n; ++i) {
        std::cout << records[i].name << std::endl;
    }
    return 0;
}
