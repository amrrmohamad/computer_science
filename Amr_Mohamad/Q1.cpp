#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0, count1 = 0, count2 = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];

    cout << "Enter the elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max = a[0];
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
        sum += a[i];
    }

    cout << "The average is: " << (double)(sum - max - min) / (n - 2) << endl;
}