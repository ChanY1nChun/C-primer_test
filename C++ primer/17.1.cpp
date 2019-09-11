#include <iostream>
#include <tuple>

using namespace std;

int main() {
    tuple<int,int,int> mytu{10,20,30};

    cout << get<0>(mytu) << endl;
    cout << get<1>(mytu) << endl;
    cout << get<2>(mytu) << endl;

    auto mytu2 = make_tuple(10,20,30);

    cout << get<0>(mytu2) << endl;
    cout << get<1>(mytu2) << endl;
    cout << get<2>(mytu2) << endl;

    typedef decltype(mytu2) trans;

    size_t sz = tuple_size<trans>::value;
    cout << sz << endl;

    tuple_element<0, trans>::type cnt = get<1>(mytu2);
    cout << cnt << endl;

    return 0;
}
