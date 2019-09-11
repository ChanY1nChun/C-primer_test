#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string word;
    cin >> word;
    for(auto c : word)
        if(!ispunct(c))
            cout << c;

    return 0;
}
