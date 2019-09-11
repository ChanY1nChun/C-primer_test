#include <iostream>

int main()
{
    int i,j,a,b;
    std::cout << "Enter two numbers: ";
    std::cin >> i >> j;
    a = i + j;
    b = i * j;
    std::cout << " i + j = " << a << std::endl;
    std::cout << " i * j = " << b << std::endl;
    return 0;
}
