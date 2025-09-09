#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int a) {
    int s = 0;
    int e = n-1;
    while(s <= e) {
         int mid = (s + e) / 2;
        if(arr[mid] == a) {
            return mid;
        }
        else if(arr[mid] > a) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return  -1; 
}
int main() {
    int size,key;
    cout<< "Enter the size of an array: ";
    cin>> size;
    int arr[size];
    cout<< "Enter the key: ";
    cin>> key;
    for(int i=0;i<size;i++) {
        cin>> arr[i];
    }
    int ans = binarySearch(arr,size,key);
    if(ans == -1) {
        cout<<"Key not found" <<endl;
    }
    else {
        cout<<"Key found at index "<< ans <<endl;
    }

return 0;

}
