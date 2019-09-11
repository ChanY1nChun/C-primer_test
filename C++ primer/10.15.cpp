#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int sz,i;
    cin >> sz >> i;
    auto y = [sz](const int i) {cout << sz + i;};
   /* cout <<*/ y(i) ;//<< endl;
    return 0;
}
