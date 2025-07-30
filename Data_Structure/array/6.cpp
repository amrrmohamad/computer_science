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

    int max =a[0] ;
    int secmax = a[0];

    for (int i = 0; i < n ; i++){
        if (a[i] > max){
            secmax = max;
            max = a[i];
        }else if (a[i] > secmax && a[i] != max){
            secmax = a[i];
        }
    }
    cout << secmax <<endl;
}
