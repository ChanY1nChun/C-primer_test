#include <iostream>

int main()
{
    int val = 0,i = 50;
    while(i<=100)
    {
        val += i;
        i++;
    }
    std::cout << val << std::endl;
    return 0;
}
