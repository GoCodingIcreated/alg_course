#include <iostream>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
int main(int argc, char **argv) {
    srand(time(NULL));
    int n, k;
    int limit_n, limit_k, limit_len;
    limit_n = 30;
    limit_k = 100;
    limit_len = 5;
    if (argc == 5) {
        sscanf(argv[1], "%d", &limit_n);
        sscanf(argv[2], "%d", &limit_k);
    }
    else {
        return 1;
    }
    limit_n /= 2;
    limit_k /= 2;
    std::ofstream out_dat(argv[3]);
    std::ofstream out_ans(argv[4]);

    n = rand() % limit_n + limit_n;
    k = rand() % limit_k + limit_k;
    std::vector<std::string> names;
    for (int i = 0; i < n; ++i) {
        int length = rand() % limit_len + limit_len / 2;
        std::string name;
        for (int j = 0; j < length; ++j) {
            name += char(rand() % 26 + 'a');
        }
        names.push_back(name);
    }
    std::map<std::string, std::pair<int, int> > table;
    out_dat << n << ' ' << k << std::endl;
    int timer = 0;
    for (int i = 0; i < k; ++i) {
        int pos = rand() % n;
        int val = rand() % 1000;
        ++timer;
        if (table.find(names[pos]) != table.end()) {
            if (table[names[pos]].first < val) {
                table[names[pos]] = std::make_pair(val, timer);
            }
        }
        else {
            table[names[pos]] = std::make_pair(val, timer);
        }
        out_dat << names[pos] << ' ' << val << std::endl;
    }
    std::vector<std::pair<std::string, std::pair<int, int>> > result;
    for (auto it : table) {
        result.push_back(it);
    }
    std::sort(result.begin(), result.end(), [](const std::pair<std::string, std::pair<int, int>> &a,
                                        const std::pair<std::string, std::pair<int, int>> &b) -> bool
                                        {
                                            if (a.second.first == b.second.first) {
                                                return a.second.second < b.second.second;
                                            }
                                            return a.second.first > b.second.first;
                                        }
        );
    for (auto it : result) {
        out_ans << it.first << std::endl;
    }
}
