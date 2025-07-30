#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of element: ";
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    int zeros = 0;
    for (int i = 0 ; i < n ;i++){
        if (a[i] == 0){
            zeros++;
        }
    }

    for (int i = 0; i < zeros ; i++){
        a[i] = 0;
    }

    for (int i = zeros; i < n; i++){
        a[i] = 1;
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}