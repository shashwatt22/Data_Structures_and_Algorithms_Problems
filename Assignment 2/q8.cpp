#include<iostream>
using namespace std;
int NoOfDistinct(int arr[], int n) {
    int count = 0;
    for(int i=1;i<n;i++) {
        if(arr[i-1] != arr[i]) {
            count++;
        }
    }
    return count;
}
int main() {
    int n;
    cout<< "Enter n: ";
    cin>> n;
    int arr[n];

    for(int i=0;i<n;i++) {
        cin>> arr[i];
    }
    int ans = NoOfDistinct(arr,n);
    cout<< ans <<endl;
    
    return 0;
}
