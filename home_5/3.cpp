#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>
//int main() {
long long f(std::string &str) {
    //std::string str;
    //std::cin >> str;
    long long result = 0;
    for (size_t i = 1; i <= str.size(); ++i) {
        std::unordered_map<std::string, long long> counts;
        for (size_t j = 0; j + i <= str.size(); ++j) {
            auto str_tmp = str.substr(j, i);
            auto it = counts.find(str_tmp);
            if (it != counts.end()) {
                ++(it->second);
            }
            else {
                counts[str_tmp] = 1;
            }
        }
        long long max = 0;
        for (auto i : counts) {
            //std::cout << i.first << std::endl;
            max = max > i.second ? max : i.second;
        }
        //std::cout << max << ' ';
        result = std::max<long long>(result, max * i);
    }
    //std::cout << std::endl;
    //std::cout << result << std::endl;
    return result;
}

