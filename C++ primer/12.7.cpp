#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> factory() {
    return make_shared<vector<int>>();
}

void process( shared_ptr<vector<int>> ptr ) {
    int num;
    while( cin >> num )
        ptr->push_back( num );
}

void print( shared_ptr<vector<int>> ptr ) {
    for( vector<int>::iterator i = ptr->begin(); i != ptr->end(); ++i )
        cout << *i << ' ';

    cout << endl;
}

int main() {
    shared_ptr<vector<int>> ptr = factory();
    process( ptr );
    print( ptr );

    return 0;
}
