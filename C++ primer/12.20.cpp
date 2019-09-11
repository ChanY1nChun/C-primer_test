#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
using namespace std;

class StrBlob;
class StrBlobPtr {
public:
    StrBlobPtr() : curr( 0 ) { }
    StrBlobPtr( StrBlob &a, size_t sz = 0 );
    string& deref() const {
        auto p = check( 0, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check( curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    bool operator!=( const StrBlobPtr &rhs ) {
        return curr != rhs.curr;
    }


private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
    shared_ptr<vector<string>> check( size_t i, const string &msg ) const {
        auto ret = wptr.lock();
        if( !ret )
            throw runtime_error("unbound StrBlobPtr");
        if( i >= ret->size() )
            throw out_of_range( msg );
        return ret;
    }
};

class StrBlob {
public:
    friend class StrBlobPtr;

    typedef vector<string>::size_type size_type;
    StrBlob() : data( make_shared<vector<string>>() ) { }
    StrBlob( initializer_list<string> il ) : data( make_shared<vector<string>>( il ) )  { }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() { return StrBlobPtr( *this, data->size() ); }



    void push_back( const string &e ) { data->push_back( e ); }
    void pop_back() {
        check( 0, "pop_back on empty StrBlob");
        return data->pop_back();
    }

    string& front() {
        check( 0, "front on empty StrBlob");
        return data->front();
    }

    string& back() {
        check( 0, "back on empty StrBlob");
        return data->back();
    }

    string& front() const {
        check( 0, "front on empty StrBlob");
        return data->front();
    }

    string& back() const {
        check( 0, "back on empty StrBlob");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    void check( size_type i, const string &msg ) const {
        if( i >= data->size() )
            throw out_of_range( msg );
    }
};
StrBlobPtr::StrBlobPtr( StrBlob &a, size_t sz) :
    wptr( a.data ), curr( sz ) { }

int main() {
    ifstream in("ifile.txt");
    string s;
    StrBlob str;
    while( getline( in, s ) )
        str.push_back( s );
    for( StrBlobPtr i(str.begin()); i != str.end(); i.incr() )
        cout << i.deref() << ' ';
    cout << endl;

    return 0;
}
