#include <iostream>
#include <string>
using namespace std;

void check1() {
    string s;
    cout << "R.E. 1: a*\n";
    cout << "Input (# for empty string): ";
    cin >> s;
    if (s == "#")
        s = "";

    int i = 0;
    while (i < s.length() && s[i] == 'a')
        i++;

    if (i == s.length())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
}

void check2() {
    string s;
    cout << "R.E. 2: (a+b)*\n";
    cout << "Input (# for empty string): ";
    cin >> s;
    if (s == "#")
        s = "";

    int i = 0;
    while (i < s.length() && (s[i] == 'a' || s[i] == 'b'))
        i++;

    if (i == s.length())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
}

void check3() {
    string s;
    cout << "R.E. 3: ab*(a+b)*\n";
    cout << "Input (# for empty string): ";
    cin >> s;
    if (s == "#")
        s = "";

    if (s.length() == 0 || s[0] != 'a') {
        cout << "Rejected\n";
        return;
    }

    int i = 1;
    while (i < s.length() && (s[i] == 'a' || s[i] == 'b'))
        i++;

    if (i == s.length())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
}

void check4() {
    string s;
    cout << "R.E. 4: a*b+ab*(a*+b)\n";
    cout << "Input (# for empty string): ";
    cin >> s;
    if (s == "#")
        s = "";

    int n = s.length();
    int i;

    i = 0;
    while (i < n && s[i] == 'a')
        i++;
    if (i == n - 1 && s[i] == 'b') {
        cout << "Accepted\n";
        return;
    }

    if (n == 0 || s[0] != 'a') {
        cout << "Rejected\n";
        return;
    }
    i = 1;
    while (i < n && s[i] == 'b')
        i++;
    while (i < n && s[i] == 'a')
        i++;

    if (i == n)
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. a*\n";
        cout << "2. (a+b)*\n";
        cout << "3. ab*(a+b)*\n";
        cout << "4. a*b+ab*(a*+b)\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 0)
            break;
        else if (choice == 1)
            check1();
        else if (choice == 2)
            check2();
        else if (choice == 3)
            check3();
        else if (choice == 4)
            check4();
        else
            cout << "Invalid choice\n";
    }

    return 0;
}
