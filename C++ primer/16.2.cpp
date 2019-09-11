#include <iostream>
#include <string>
using namespace std;

template<typename T> int compare( const T &lhs, const T &rhs )
{
    if( lhs < rhs ) return -1;
    if( lhs > rhs ) return 1;

}

int main() {

    string a = "s";
    string b = "a";
    cout << compare( a,b ) << endl;

    return 0;
}
