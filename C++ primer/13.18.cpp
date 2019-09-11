#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    Employee() = default;
    Employee( string &s ) : name(s) { worknum = num++; }
    Employee( const Employee& ) = delete;
    Employee& operator=( const Employee& ) = delete;
    string _name() const { return name; }
    int _worknum() const { return worknum;}
private:
    string name;
    int worknum;
    static int num;
};

int Employee::num = 0;

int main() {
    string name1("asd");
    string name2("qwe");
    Employee a(name1);
    Employee b(name2);

    cout << a._name() << a._worknum() << endl;
    cout << b._name() << b._worknum() << endl;
    return 0;
}
