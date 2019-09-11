#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int>::size_type count(vector<int>::const_iterator beg_vec, vector<int>::const_iterator end_vec, int val)
{
    vector<int>::size_type i = 0;
    while(beg_vec != end_vec) {
        if(*beg_vec == val)
            ++i;
        ++beg_vec;
    }
    return i;
}
int main()
{
    vector<int> vec_int{0,1,2,3,4,5,5,5,5,6,7,8,9,10};
    int i;
    cin >> i;
    vector<int>::size_type cnt = count(vec_int.cbegin(), vec_int.cend(), i);
    cout << cnt << endl;
    return 0;
}
