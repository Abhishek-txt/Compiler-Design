#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    int len;

    cout << "Enter a line: ";
    getline(cin, line);
    len = line.length();

    if (line[0] == '/' && line[1] == '/')
    {
        cout << "single line comment" << endl;
    }
    else if (line[0] == '/' && line[1] == '*')
    {
        int found = 0;

        if (len >= 4 && line[len - 2] == '*' && line[len - 1] == '/')
            found = 1;

        while (found == 0)
        {
            getline(cin, line);
            len = line.length();
            if (len >= 2 && line[len - 2] == '*' && line[len - 1] == '/')
                found = 1;
        }

        cout << "multi line comment" << endl;
    }
    else
    {
        cout << "not a comment" << endl;
    }

    return 0;
}
