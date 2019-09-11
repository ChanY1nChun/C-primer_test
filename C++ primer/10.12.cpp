#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Sales_data {
public:
    Sales_data(string s);
    Sales_data():Sales_data("0") {}
    string get_isbn() const {return isbn;}
private:
    string isbn;
};

Sales_data::Sales_data(string s) : isbn(s) {}

bool compareIsbn(const Sales_data &S1, const Sales_data &S2)
{
    return S1.get_isbn() < S2.get_isbn();
}
int main()
{
    vector<Sales_data> vec_Sales;
    string isbn1,isbn2;
    cin >> isbn1 >> isbn2;
    Sales_data S1{isbn1},S2{isbn2};
    bool flag = compareIsbn(S1, S2);
    cout << flag << endl;

    return 0;
}
