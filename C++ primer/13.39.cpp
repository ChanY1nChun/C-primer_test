#include <iostream>
#include <cstddef>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec( const StrVec&);
    StrVec& operator=( const StrVec& );
    StrVec( initializer_list<string> il ) {
        auto new_data = alloc_n_copy( il.begin(), il.end() );
        elements = new_data.first;
        first_free = cap = new_data.second;
    }
    ~StrVec() { free(); }

    void push_back( const string& );
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    //void reserve( size_t );
    //void resize( size_ t );

private:
    allocator<string> alloc;
    void chk_n_alloc() { if( size() == capacity() ) reallocate(); }
    pair<string*, string*> alloc_n_copy( const string*, const string* );
    void free();
    void reallocate();
    void chk_n_move( size_t );
    string *elements;
    string *first_free;
    string *cap;
};

void StrVec::push_back( const string &s ) {
    chk_n_alloc();
    alloc.construct( first_free++, s );
}

pair<string*, string*>
StrVec::alloc_n_copy( const string *b, const string *e ) {
    auto new_data = alloc.allocate( e - b );
    return { new_data, uninitialized_copy( b, e, new_data ) };
}

void StrVec::free() {
    if( elements ) {
        for( auto p = first_free; p != elements; )
            alloc.destroy( --p );
        alloc.deallocate( elements, cap - elements );
    }
}

StrVec::StrVec( const StrVec &s ) {
    auto new_data = alloc_n_copy( s.begin(), s.end() );
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec& StrVec::operator=( const StrVec &rhs ) {
    auto new_data = alloc_n_copy( rhs.begin(), rhs.end() );
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;


    chk_n_move( new_capacity );

}
void StrVec::chk_n_move( size_t capacity ) {
    auto new_data = alloc.allocate( capacity );

    auto dest = new_data;
    auto elem = elements;

    for( size_t i = 0; i != size(); ++i )
        alloc.construct( dest, std::move( *elem++ ) );
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + capacity;
}

