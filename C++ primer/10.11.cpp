#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &vec)
{
    //stable_sort(vec.begin(), vec.end(), isShorter);
    sort(vec.begin(), vec.end());
    for(vector<string>::value_type &i : vec)
        cout << i << ends;
    cout << endl;
    vector<string>::iterator vec_end = unique(vec.begin(), vec.end());
    for(vector<string>::value_type &i : vec)
        cout << i << ends;
    cout << endl;
    vec.erase(vec_end, vec.end());
    stable_sort(vec.begin(), vec.end(), isShorter);
    for(vector<string>::value_type &i : vec)
        cout << i << ends;
    cout << endl;
}
int main()
{
    vector<string> vec_str{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(vec_str);
    return 0;
}
