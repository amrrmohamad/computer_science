#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n], b[n];

    cout << "Enter the elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int a[6] = {2, 10, 70, 210, 840, 4200};
    // int b[6];

    int j = 0;

    for (int i = n; i > 1; i--)
    {
        b[j] = a[i - 1] / a[i - 2];
        j++;
    }
    b[n - 1] = a[0];

    for (int i = 0; i < 6; i++)
    {
        cout << b[i] << endl;
    }
}