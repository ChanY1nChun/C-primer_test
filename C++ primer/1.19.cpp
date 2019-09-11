#include <iostream>

int main()
{
    int i,j;
    std::cout << "Enter two numbers : ";
    std::cin >> i >> j;
    if(i <= j)
    {
        while(i <= j)
        {
            std::cout << i << std::endl;
            i++;
        }
    }
    else
    {
        while(j <= i)
        {
            std::cout << j << std::endl;
            j++;
        }
    }



    return 0;
}
