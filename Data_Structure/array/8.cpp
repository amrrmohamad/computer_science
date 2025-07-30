#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of element: ";
    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    int maxr = a[n-1];
    for (int i = n - 2; i >= 0; i--){
        if (a[i] > maxr){
            maxr = a[i];
            cout << maxr << endl;
        }
    }
}