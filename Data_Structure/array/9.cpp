#include <iostream>

using namespace std;

int main (){
    int n, sum = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    int max = a[0];
    int min = a[0];

    for (int i = 0; i < n ;i++){
        if (a[i] > max){
            max = a[i];
        }
        if (a[i] < min){
            min = a[i];
        }
    }

    for (int i = 0; i < n ; i++){
        sum += a[i];
    }
    cout << sum << max << min << n;

    cout << "The average is : "<< (double) (sum - max - min) / (n - 2) <<endl;
}