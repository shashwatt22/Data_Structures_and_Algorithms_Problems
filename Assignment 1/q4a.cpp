#include<iostream>
using namespace std;
int main() {
    int size;
    cout<< "Enter the size of the array: ";
    cin>> size;
    int arr[size];
    cout<< "Enter the elements of the array: ";
    for(int i=0;i<size;i++) {
        cin>> arr[i];
    }
    int a=0,b=size-1;
    for(int i=0;i<size;i++) {
        if(a<b) {
            swap(arr[a],arr[b]);
        }
        a++;
        b--;
    }
    for(int i=0;i<size;i++) {
        cout<< arr[i] <<" ";
    }
    return 0;
}
