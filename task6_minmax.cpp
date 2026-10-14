#include <iostream>
using namespace std;

int main()
{
    int n, i;
    int a[100];
    int min, max;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    min = a[0];
    max = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;

    return 0;
}
