#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isLess5(const string &s)
{
    return (s.size() >= 5);
}
int main()
{
    string str;
    vector<string> vec_str;
    while(cin >> str)
        vec_str.push_back(str);
    vector<string>::iterator end_vec = partition(vec_str.begin(),vec_str.end(),isLess5);
    vec_str.erase(end_vec, vec_str.end());
    for(const vector<string>::value_type &i : vec_str)
        cout << i << ends;
    cout << endl;
    return 0;
}
