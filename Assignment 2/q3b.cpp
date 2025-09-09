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

    int s = 0;
    int e = n-2;
    for(int i=0;i<n-1;i++) {
    int mid = (s + e) / 2;
    if(arr[mid]-mid == 1) {
        s = mid + 1;
    }
    else {
        e = mid - 1;
    } 
}
cout<< "The missing element is: " <<(arr[s] + arr[e]) / 2 <<endl;
    return 0;
}
