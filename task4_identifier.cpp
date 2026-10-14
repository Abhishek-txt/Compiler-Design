#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int i, flag = 1;

    cout << "Enter something: ";
    cin >> str;

    if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') || str[0] == '_')
    {
        for (i = 1; i < str.length(); i++)
        {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_' || (str[i] >= '0' && str[i] <= '9'))
            {
                flag = flag;
            }
            else
            {
                flag = 0;
            }
        }
    }
    else
    {
        flag = 0;
    }

    if (flag == 1)
        cout << "identifier" << endl;
    else
        cout << "not an identifier" << endl;

    return 0;
}
