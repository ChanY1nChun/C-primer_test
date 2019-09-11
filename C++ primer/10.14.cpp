#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int i,j;
    cin >> i >> j;
    auto k = [](const int i, const int j) {return (i + j);};
    cout << k(i,j) << endl;

    return 0;
}
