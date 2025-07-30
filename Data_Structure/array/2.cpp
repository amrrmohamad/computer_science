#include <iostream>

using namespace std;

int main(){
    int n, cp = 0, cn = 0, cz = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i] > 0){
            cp++;
        } else if (a[i] < 0){
            cn++;
        }else{
            cz++;
        }
    }
    cout << "the number of positive is: " << cp << "\n and nigative is: " << cn << "\n and zeros is: " << cz << endl;
}