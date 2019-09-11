#include <iostream>
#include <vector>

using namespace std;

vector<int>* factory() {
    return new vector<int>();
}

void process( vector<int> *ptr ) {
    int num;
    while( cin >> num ) {
        ptr->push_back( num );
    }
}

void print( vector<int> *ptr ) {
    for( vector<int>::iterator i = ptr->begin(); i != ptr->end(); ++i )
        cout << *i << ' ' ;
    cout << endl;
    delete ptr;
    ptr = nullptr;
}

int main() {

    vector<int> *ptr = factory();
    process( ptr );
    print( ptr );

    return 0;
}
