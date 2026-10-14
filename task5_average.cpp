#include <iostream>
using namespace std;

int main()
{
    int n, i;
    int a[100];
    float sum = 0, avg;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }

    avg = sum / n;
    cout << "Average = " << avg << endl;

    return 0;
}
