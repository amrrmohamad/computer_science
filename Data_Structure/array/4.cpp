#include <iostream>

using namespace std;

int main(){
    int n, maxfqn, maxfq = 0;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cout << "enter the: "<< i+1 << " element" << endl;
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (a[i] == a[j]){
                count++;
            }
        }
        if (count > maxfq){
            maxfq = count;
            maxfqn = a[i];
        }
    }

    cout << "the largest occurance is: " << maxfq  << " and this number is: " << maxfqn << endl;
}