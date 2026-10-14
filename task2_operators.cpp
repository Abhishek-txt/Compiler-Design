#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int i, count = 0;

    cout << "Enter expression: ";
    cin >> str;

    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '=')
        {
            count = count + 1;
            cout << "operator" << count << ": " << str[i] << endl;
        }
    }

    if (count == 0)
        cout << "no operator found" << endl;

    return 0;
}
