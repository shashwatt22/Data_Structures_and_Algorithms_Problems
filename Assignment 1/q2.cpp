#include<iostream>
using namespace std;
void deleteElement(int arr[],int n,int pos) {
    for(int i=pos;i<n;i++) {
        arr[i] = arr[i+1];
    }
}
int main() {
    int size;
    cout<< "Enter the size of an array: ";
    cin>> size;
int arr[size];
cout<< "Enter the elements of an array: ";
for(int i=0;i<size;i++) {
    cin>> arr[i];
}
for(int i=0;i<size;i++) {
    for(int j=i+1;j<size;j++) {
        if(arr[i]==arr[j]) {
            deleteElement(arr,size,j);
            size--;
        }
    }
}
cout<< "Array after deleting duplicates: ";
for(int i=0;i<size;i++) {
    cout<< arr[i] <<" ";
}
return 0;
}
