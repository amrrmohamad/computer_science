#include <iostream>

using namespace std;

int main(){
    int n, temp = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] == a[j]){
                bool found = false;
                for (int l = 0; l < temp ; l++){
                    if(b[l] == a[i]){
                        found = true;
                        break;
                    }
                }
                if (!found){
                    b[temp] = a[i];
                    temp++;
                }
                break;
            }
        }
    }

    for (int i = 0; i < temp; i++){
        cout << b[i] << " ," ;
    }
}