#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec_int{0,1,2,3,4,5,6,7,8,9};
    int sum = accumulate(vec_int.cbegin(),vec_int.cend(),0);
    cout << sum << endl;

    return 0;

}
