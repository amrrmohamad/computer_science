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

    for (int i = 0 ; i < n; i++){
        if (a[i] == 1 or a[i] == 0){
            cout << "the array contain 1 or zero\n";
            return 0;
        }
    }
    cout << "the array doesn't contain any 1 or zeros\n";
}