#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "Enter n: ";
    cin>> n;
    int arr[n];

    for(int i=0;i<n;i++) {
        cin>> arr[i];
    }
    int inversion = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
           if(i < j && arr[i] > arr[j]) {
        inversion++;
    } 
}
    
}
cout<< "The number of inversions are: " << inversion <<endl;
    return 0;
}
