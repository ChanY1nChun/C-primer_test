#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

void elimDups(vector<string> &vec)
{
    sort(vec.begin(), vec.end());
    for(vector<string>::value_type &i : vec)
        cout << i << ends;
    cout << endl;
    vector<string>::iterator vec_end = unique(vec.begin(), vec.end());
    for(vector<string>::value_type &i : vec)
        cout << i << ends;
    cout << endl;
    vec.erase(vec_end, vec.end());
}
int main()
{
    vector<string> vec_str;
    string word;
    while(cin >> word)
        vec_str.push_back(word);
    for(vector<string>::value_type &i : vec_str)
        cout << i << ends;
    cout << endl;
    elimDups(vec_str);
    for(vector<string>::value_type &j : vec_str)
        cout << j << ends;
    cout << endl;
    return 0;
}
