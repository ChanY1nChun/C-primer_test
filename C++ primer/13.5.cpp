#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr( const string &s = string() ) :
        ps( new string( s )), i(0) { }
    HasPtr( const HasPtr &rhs ) : ps( new string(*(rhs.ps)) ), i(rhs.i) { }
private:
    string *ps;
    int i;
};
