#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr( const string &s = string() ) :
        ps( new string( s )), i(0) { }
    HasPtr( const HasPtr &rhs ) : ps( new string(*(rhs.ps)) ), i(rhs.i) { }
    HasPtr& operator= ( const HasPtr &rhs ) {
        string *tmp = new string(*( rhs.ps ));
        delete ps;
        ps = tmp;
        i = rhs.i;
        return *this;
    }
private:
    string *ps;
    int i;
};
