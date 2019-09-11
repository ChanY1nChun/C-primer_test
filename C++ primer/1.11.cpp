#include <iostream>

int main()
{
    int i,j;
    std::cout << "Enter two numbers : ";
    std::cin >> i >> j;
    while(i <= j)
    {
        std::cout << i << std::endl;
        i++;
    }


    return 0;
}
