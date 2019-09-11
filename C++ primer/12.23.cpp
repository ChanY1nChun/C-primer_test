#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
    const char *a = "asd";
    const char *b = "zxc";

    char *p = new char[ strlen(a) + strlen(b) + 1 ];
    strcpy( p, a );
    strcat( p, b );

    cout << p << endl;
    delete [] p;
    return 0;
}
