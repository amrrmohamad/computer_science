#include <iostream>

using namespace std;

int main(){
    int n, temp;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    for (int i = 0; i < n/2; i++){
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    cout << " the revers array is: " ;
    for (int i = 0; i < n; i++){
        cout << a[i] << ", ";
    }
}