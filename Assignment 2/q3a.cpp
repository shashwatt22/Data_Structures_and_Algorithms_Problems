#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "Enter n: ";
    cin>> n;

    int arr[n-1];
    for(int i=0;i<n-1;i++) {
        cin>> arr[i];
    }
    for(int i=0;i<n-1;i++) {
        if(arr[i]-i != 1) {
            cout<< "The missing element is: " << arr[i] - 1 <<endl;
            break;
        }
    }
    return 0;
}
