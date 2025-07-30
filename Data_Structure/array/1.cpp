#include <iostream>

using namespace std;

int main (){
    int n, max = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    cout << "the largest number in array is: "<< max << endl;
    return 0;
}