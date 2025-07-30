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

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> b[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            cout << "the first array doesn't equal the sec array\n";
            return -1;
        }
    }
    cout << "the two arrays are equals\n";
    return 0;
}