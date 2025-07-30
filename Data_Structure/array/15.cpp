#include <iostream>
#include <algorithm>

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

    sort(a , a+n);
    for (int i = 0; i < n; i++){
        cout << a[i]<< endl;
    }
}