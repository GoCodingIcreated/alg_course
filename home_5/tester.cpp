#include <iostream>
#include <cstdlib>
//#include "3.cpp"
//#include "4.cpp"
int main() {
    std::string str;
    for (int i = 5000; i <= 10000; ++i) {
        str.resize(i);
        for (int j = 0; j < i; ++j) {
            str[j] = rand() % 26 + 'a';
        }
        std::cout << str << std::endl;
        return 0;
//        for (int i = 0; i < MAX_SIZE; ++i) 
 //           hash_table[i].resize(0);
   //     }
        long long res1 = 0;//f(str);
        long long res2 = 0;//f2(str);
        if (res1 == res2) {
            std::cout << "OK " << res1 << std::endl;
        }
        else {
            std::cout << "FAILED " << res1 << ' ' << res2 << ' '<< str << std::endl;
        }
    }
}
