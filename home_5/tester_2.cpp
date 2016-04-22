#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>


#include "2.cpp"

TEST(data, input) {
    Data d;
    std::ifstream in1("1.dat");
    std::ifstream in2("1.dat");
    
    in1 >> d;
    in1.close();
    std::string str;
    int val;
    in2 >> str >> val;
    in2.close();
    ASSERT_EQ(str, d.name);
    ASSERT_EQ(val, d.val);
}

TEST(data, output) {
    Data d;
    d.name = "Ivan";
    d.val = 10;
    
    std::ofstream out("2.dat");
    out << d;
    out.close();
    std::ifstream in("2.dat");
    std::string str;
    int val;
    in >> str >> val;
    in.close();
    ASSERT_EQ("Ivan", str);
    ASSERT_EQ(10, val);
}

TEST(data, equal1) {
    Data d1, d2;
    d1.name = "Nick";
    d2.name = "Ivan";
    d1.val = 10;
    d2.val = 40;
    
    ASSERT_FALSE(d1 == d2);
}

TEST(data, equal2) {
    Data d1, d2;
    d1.name = "Nick";
    d2.name = "Nick";
    d1.val = d2.val = 10;
    
    ASSERT_TRUE(d1 == d2);
}

TEST(data, equal3) {
    Data d1, d2;
    d1.name = "Nick";
    d2.name = "Nick";
    d1.val = 10;
    d2.val = 12415;
    ASSERT_TRUE(d1 == d2);
}

TEST(data, equal4) {
    Data d1, d2;
    d1.name = "Nick";
    d2.name = "Ivan";
    d1.val = d2.val = 10;
    ASSERT_FALSE(d1 == d2);
}

TEST(data, equal5) {
    Data d1, d2;
    d1.name = "Nick";
    d2.name = "Ivan";
    d1.val = 15;
    d2.val = 123;
    ASSERT_FALSE(d1 == d2);
    
    d2.name = "Nick";
    ASSERT_TRUE(d1 == d2);
    
    d1.name = "Sasha";
    ASSERT_FALSE(d1 == d2);
}

TEST(data, less1) {
    Data d1, d2;
    d1.name = "Alex";
    d2.name = "Bogdan";
    d1.val = 5;
    d2.val = 10;
    ASSERT_TRUE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
}

TEST(data, less2) {
    Data d1, d2;
    d1.name = "Alex";
    d2.name = "Alex";
    d1.val = d2.val = 10;
    ASSERT_FALSE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
}

TEST(data, less3) {
    Data d1, d2;
    d1.name = "Alex";
    d2.name = "Alex";
    d1.val = 10;
    d2.val = 20;
    ASSERT_FALSE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
}

TEST(data, less4) {
    Data d1, d2;
    d1.name = "Gosha";
    d2.name = "Natasha";
    d1.val = d2.val = 1123213;
    ASSERT_TRUE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
}

TEST(AVL, create) {
    try {
        AVL avl;
    }
    catch (...) {
        FAIL();
    }
}

TEST(AVL, insert) {
    AVL avl;
    
    Data d;
    d.name = "Aaaa";
    d.val = 1;
    avl.insert(d);
    
    ASSERT_EQ(std::string("Aaaa 1\n"), avl.print());

    Data d2;
    d2.name = "Bbbbb";
    d2.val = 2;
    avl.insert(d2);
    
    ASSERT_EQ(std::string("Aaaa 1\nBbbbb 2\n"), avl.print());

    Data d3;
    d3.name = "Ccc";
    d3.val = 3;
    avl.insert(d3);

    ASSERT_EQ(std::string("Aaaa 1\nBbbbb 2\nCcc 3\n"), avl.print());

    Data d4;
    d4.name = "A";
    d4.val = 0;
    avl.insert(d4);

    ASSERT_EQ(std::string("A 0\nAaaa 1\nBbbbb 2\nCcc 3\n"), avl.print());
}

TEST(AVL, insert2) {
    AVL avl;
    std::vector<std::string> input;
    std::string out;
    for (int i = 0; i < 100; ++i) {
        std::stringstream ss;
        Data d;
        char ch[i + 1];
        for (int j = 0; j < i; ++j) {
            ch[j] = (i + j) % 26 + 'a';
        }
        ch[i] = 0;
        d.name = std::string(ch);
        d.val = i;
        ss << d << '\n';
        out = ss.str();
        input.push_back(out);
        avl.insert(d);
    }
    std::sort(input.begin(), input.end());
    out = "";
    for (auto it : input) {
        out += it;
    }
    ASSERT_EQ(out, avl.print());
}

TEST(AVL, change) {
    AVL avl;
    Data d1, d2, d3, d4, d5;
    d1.name = "aaa";
    d1.val = 1;

    d2.name = "bbb";
    d2.val = 2;

    d3.name = "ccc";
    d3.val = 3;

    d4.name = "ddd";
    d4.val = 4;

    d5.name = "eee";
    d5.val = 5;

    avl.insert(d1);
    avl.insert(d2);
    avl.insert(d3);
    avl.insert(d4);
    avl.insert(d5);
    std::string out = "aaa 1\nbbb 2\nccc 3\nddd 4\neee 5\n";
    
    ASSERT_EQ(out, avl.print());

    d2.val = 10;
    avl.change(d2);
    
    d3.val = 15;
    avl.change(d3);

    out = "aaa 1\nbbb 10\nccc 15\nddd 4\neee 5\n";
    ASSERT_EQ(out, avl.print());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    return RUN_ALL_TESTS();
}
