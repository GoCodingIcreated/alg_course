#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>


#include "2.cpp"

TEST(AVLData, input) {
    AVLData d;
    std::ifstream in1("tests/1.dat");
    std::ifstream in2("tests/1.dat");
    
    in1 >> d;
    in1.close();
    std::string str;
    int val;
    in2 >> str >> val;
    in2.close();
    ASSERT_EQ(str, d.name);
    ASSERT_EQ(val, d.heap_pos);
}

TEST(AVLData, output) {
    AVLData d;
    d.name = "Ivan";
    d.heap_pos = 10;
    
    std::ofstream out("tests/2.dat");
    out << d;
    out.close();
    std::ifstream in("tests/2.dat");
    std::string str;
    int val;
    in >> str >> val;
    in.close();
    ASSERT_EQ("Ivan", str);
    ASSERT_EQ(10, val);
}

TEST(AVLData, equal) {
    AVLData d1, d2;
    d1.name = "Nick";
    d2.name = "Ivan";
    d1.heap_pos = 10;
    d2.heap_pos = 40;
    ASSERT_FALSE(d1 == d2);

    AVLData d3, d4;
    d3.name = "Nick";
    d4.name = "Nick";
    d3.heap_pos = d4.heap_pos = 10;
    ASSERT_TRUE(d3 == d4);

    d1.name = "Nick";
    d2.name = "Nick";
    d1.heap_pos = 10;
    d2.heap_pos = 12415;
    ASSERT_TRUE(d1 == d2);
    
    d1.name = "Nick";
    d2.name = "Ivan";
    d1.heap_pos = d2.heap_pos = 10;
    ASSERT_FALSE(d1 == d2);
    
    d1.name = "Nick";
    d2.name = "Ivan";
    d1.heap_pos = 15;
    d2.heap_pos = 123;
    ASSERT_FALSE(d1 == d2);
    d2.name = "Nick";
    ASSERT_TRUE(d1 == d2);
    
    d1.name = "Sasha";
    ASSERT_FALSE(d1 == d2);
}

TEST(AVLData, less) {
    AVLData d1, d2;
    d1.name = "Alex";
    d2.name = "Bogdan";
    d1.heap_pos = 5;
    d2.heap_pos = 10;
    ASSERT_TRUE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
    
    d1.name = "Alex";
    d2.name = "Alex";
    d1.heap_pos = d2.heap_pos = 10;
    ASSERT_FALSE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
    
    d1.name = "Alex";
    d2.name = "Alex";
    d1.heap_pos = 10;
    d2.heap_pos = 20;
    ASSERT_FALSE(d1 < d2);
    ASSERT_FALSE(d2 < d1);
    
    d1.name = "Gosha";
    d2.name = "Natasha";
    d1.heap_pos = d2.heap_pos = 1123213;
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

/*
TEST(AVL, insert) {
    AVL avl;
    AVLData d;
    Heap heap;
    HeapData heap_data;
    heap_data.priority = 1;

    d.name = "Aaaa";
    d.heap_pos = 1;
    avl.insert(heap, heap_data, d);
    ASSERT_EQ(std::string("Aaaa 1\n"), avl.print());

    AVLData d2;
    d2.name = "Bbbbb";
    d2.heap_pos = 2;
    avl.insert(heap, heap_data, d2);
    ASSERT_EQ(std::string("Aaaa 1\nBbbbb 2\n"), avl.print());

    AVLData d3;
    d3.name = "Ccc";
    d3.heap_pos = 3;
    avl.insert(heap, heap_data, d3);
    ASSERT_EQ(std::string("Aaaa 1\nBbbbb 2\nCcc 3\n"), avl.print());

    AVLData d4;
    d4.name = "A";
    d4.heap_pos = 0;
    avl.insert(heap, heap_data, d4);
    ASSERT_EQ(std::string("A 0\nAaaa 1\nBbbbb 2\nCcc 3\n"), avl.print());
}

TEST(AVL, insert2) {
    AVL avl;
    Heap heap;
    HeapData heap_data;
    heap_data.priority = 1;
    std::vector<std::string> input;
    std::string out;
    for (int i = 0; i < 100; ++i) {
        std::stringstream ss;
        AVLData d;
        char ch[i + 1];
        for (int j = 0; j < i; ++j) {
            ch[j] = (i + j) % 26 + 'a';
        }
        ch[i] = 0;
        d.name = std::string(ch);
        d.heap_pos = i;
        ss << d << '\n';
        out = ss.str();
        input.push_back(out);
        avl.insert(heap, heap_data, d);
    }
    std::sort(input.begin(), input.end());
    out = "";
    for (auto it : input) {
        out += it;
    }
    ASSERT_EQ(out, avl.print());
}
*/
TEST(AVL, change) {
    AVL avl;
    AVLData d1, d2, d3, d4, d5;
    Heap heap;
    HeapData heap_data;
    heap_data.priority = 1;
    
    d1.name = "aaa";
    d1.heap_pos = 1;

    d2.name = "bbb";
    d2.heap_pos = 2;

    d3.name = "ccc";
    d3.heap_pos = 3;

    d4.name = "ddd";
    d4.heap_pos = 4;

    d5.name = "eee";
    d5.heap_pos = 5;

    avl.insert(heap, heap_data, d1);
    avl.insert(heap, heap_data, d2);
    avl.insert(heap, heap_data, d3);
    avl.insert(heap, heap_data, d4);
    avl.insert(heap, heap_data, d5);
    std::string out = "aaa 1\nbbb 2\nccc 3\nddd 4\neee 5\n";
    
    ASSERT_EQ(out, avl.print());

    d2.heap_pos = 10;
    avl.change(d2);
    
    d3.heap_pos = 15;
    avl.change(d3);

    out = "aaa 1\nbbb 10\nccc 15\nddd 4\neee 5\n";
    ASSERT_EQ(out, avl.print());
}


TEST(Heap, add) {
    Heap heap;
    HeapData d[4];
    for (int i = 0; i < 4; ++i) {
        d[i].priority = i + 1;
    }

    for (int i = 0; i < 4; ++i) {
        heap.add(d[i]);
        ASSERT_EQ(d[i].priority, heap.get_max().priority);
        ASSERT_EQ(d[i].node, heap.get_max().node);
    }
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(d[3 - i].priority, heap.get_max().priority);
        ASSERT_EQ(d[3 - i].node, heap.get_max().node);
        heap.pop_max();
    }
    ASSERT_TRUE(heap.empty());

    for (int i = 3; i >= 0; --i) {
        heap.add(d[i]);
        ASSERT_EQ(d[3].node, heap.get_max().node);
        ASSERT_EQ(d[3].priority, heap.get_max().priority);
    }
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(d[3 - i].node, heap.get_max().node);
        ASSERT_EQ(d[3 - i].priority, heap.get_max().priority);
        heap.pop_max();
    }
    ASSERT_TRUE(heap.empty());
}


TEST(Heap, add2) {
    Heap heap;
    std::vector<HeapData> input;
    std::string out;
    for (int i = 0; i < 100; ++i) {
        HeapData d;
        d.priority = rand() % 1000;
        input.push_back(d);
        heap.add(input.back());
    }
    std::sort(input.rbegin(), input.rend());
    for (auto it : input) {
        ASSERT_EQ(it.node, heap.get_max().node);
        ASSERT_EQ(it.priority, heap.get_max().priority);
        heap.pop_max();
    }
}

void test_function(std::ifstream &input, std::ifstream &input_answer, std::stringstream &out) {
    main_function(input, out);
    std::string str, str2;
    while (input_answer >> str) {
        out >> str2;
        std::cerr << str2 << std::endl;
        ASSERT_EQ(str, str2);
    }
    std::cerr << std::endl;
    if (out >> str2) {
        FAIL() << str2 << std::endl;
    }
}
TEST(Solution, DefaultTest) {
    std::ifstream input("tests/3.dat");
    std::ifstream input_answer("tests/3.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}

TEST(Solution, IncreaseSequence) {
    std::ifstream input("tests/4.dat");
    std::ifstream input_answer("tests/4.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}

TEST(Solution, DecreaseSequence) {
    std::ifstream input("tests/5.dat");
    std::ifstream input_answer("tests/5.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}

TEST(Solution, RandomSequence1) {
    std::ifstream input("tests/6.dat");
    std::ifstream input_answer("tests/6.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}

TEST(Solution, RandomSequence2) {
    std::ifstream input("tests/7.dat");
    std::ifstream input_answer("tests/7.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}

TEST(Solution, RandomSequence3) {
    std::ifstream input("tests/8.dat");
    std::ifstream input_answer("tests/8.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}

TEST(Solution, RandomSequence4) {
    std::ifstream input("tests/9.dat");
    std::ifstream input_answer("tests/9.ans");
    std::stringstream out;
    test_function(input, input_answer, out);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    return RUN_ALL_TESTS();
}
