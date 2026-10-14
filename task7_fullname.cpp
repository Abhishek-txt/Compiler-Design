#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fname, lname, fullname;

    cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;

    fullname = fname + " " + lname;
    cout << "full name = " << fullname << endl;

    return 0;
}
