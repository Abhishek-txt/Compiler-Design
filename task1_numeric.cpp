#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int i, flag = 1;

    cout << "Enter something: ";
    cin >> str;

    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            flag = flag;
        }
        else
        {
            flag = 0;
        }
    }

    if (flag == 1)
        cout << "numeric constant" << endl;
    else
        cout << "not numeric" << endl;

    return 0;
}
