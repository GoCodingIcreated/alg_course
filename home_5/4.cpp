#include <iostream>
#include <vector>
const int HASH_MOD = 100 * 1000 + 3;
const int HASH = 31;
const int HASH2 = 37;
const int HASH_MOD2 = 1000 * 1000 + 3;
const int MAX_SIZE = 100 * 1000 + 30;

struct Data {
    //int hash2;
    short begin;
    short length;
    Data() {
        begin = length = 0;
    }
    Data(int b, int l) {
        //hash2 = h;
        begin = b;
        length = l;
    }
};
std::vector<std::pair<Data, int> > hash_table[MAX_SIZE];



int main() {
//long long f2(std::string str) {
    std::string str; //
    std::cin >> str; //
    std::vector<long long> maxs(str.size(), 1);
    int L = str.size();
    for (size_t begin = 0; begin < L; ++begin) {
        int hash = 0;
        ///int hash2 = 0;
        for (size_t end = begin; end < L; ++end) {
            hash = (hash * HASH + (str[end] - 'a' + 1)) % HASH_MOD;
            //hash2 = (hash2 * HASH2 + (str[end] - 'a' + 2)) % HASH_MOD2;
            int was_found = 0;
            for (auto it = hash_table[hash].begin(); it != hash_table[hash].end(); ++it) {
                if (str.substr(it->first.begin, it->first.length) == str.substr(begin, end - begin + 1)) {
                    it->second++;
                    if (it->second > maxs[end - begin]) {
                        maxs[end - begin] = it->second;
                    }
                    was_found = 1;
                    break;
                }
            }
            if (!was_found) {
                hash_table[hash].push_back(std::make_pair(Data(begin, end - begin + 1), 1));
            }
            //++hash_table[hash];
            //if (hash_table[hash] > 0) {
            //    std::cout << str.substr(begin, end - begin + 1) << "(" << hash << ',' << hash_table[hash] << ")\n";
            //}
        }
    }
    unsigned long long result = 0;
/*    for (auto i : maxs) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;*/
    for (size_t len = 0; len < str.size(); ++len) {
        if (maxs[len] * (len + 1) > result) {
            result = maxs[len] * (len + 1);
        }
    }
    std::cout << result << std::endl; //
    //return result;
}
/*
int main() {
    std::string str("agloddktdjizynyoesuozryityjrifximkyrokktvusuiqiojfckyatryekijksvusokcyeav");
    std::cout << f2(str) << std::endl;

}*/
