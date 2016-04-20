#include <iostream>

class A 
{
public:
    const int c = 3;
};

int main()  {
    A a;
    std::cout << a.c;
}
