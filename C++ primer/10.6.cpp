#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    fill_n(back_inserter(vec),10,0);
    for(auto &i : vec)
        cout << i << ends;
    cout << endl;

    return 0;
}
