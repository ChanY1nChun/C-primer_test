#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &s)
{
    sort(s.begin(), s.end());
    vector<string>::iterator end_unique = unique(s.begin(), s.end());
    s.erase(end_unique, s.end());
}

void biggies(vector<string> &s, vector<string>::size_type sz)
{
    elimDups(s);
    stable_sort(s.begin(), s.end(),
                [](const string &a, const string &b)
                {return a.size() < b.size(); });
    vector<string>::iterator wc = find_if(s.begin(), s.end(),
                                          [sz](const string &i) {return i.size()>sz; });
    for_each(wc, s.end(),
             [](const string &b) {cout << b << ends; });
    cout << endl;
}
int main()
{
    vector<string> vec_str;
    string word;
    vector<string>::size_type sz = 3;
    while(cin >> word)
        vec_str.push_back(word);
    biggies(vec_str,sz);
    return 0;
}
