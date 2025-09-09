#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "Enter any number(1-6): ";
    cin>> n;

    switch(n) {
        case 1: int arr[10];
        break;
        case 2: int brr[10];
        for(int i=0;i<5;i++) {
            cin>> brr[i];
        }
        for(int i=0;i<5;i++) {
            cout<< brr[i] <<" ";
        }
        break;
        case 3: int a,pos;
        int crr[10];
        for(int i=0;i<5;i++) {
            cin>> crr[i];
        }
        cout<< "Enter the element you want to insert: ";
        cin>> a;
        cout<< "Enter the position in which you want to insert the element: ";
        cin>> pos;
        for(int i=4;i>=pos-1;i--) {
            crr[i+1] = crr[i];
        }
        crr[pos-1] = a;
        for(int i=0;i<6;i++) {
            cout<< crr[i] <<" ";
        }
        break;
        case 4: int b;
        int drr[10];
        for(int i=0;i<5;i++) {
            cin>> drr[i];
        }
        cout<< "Enter the position of the element you want to delete: ";
        cin>> b;
        for(int i=b;i<=4;i++) {
            drr[i-1] = drr[i];
        }
        for(int i=0;i<4;i++) {
            cout<< drr[i] <<" ";
        }
        break;
        case 5: int key;
        int j=0;
        int err[10];
        for(int i=0;i<5;i++) {
            cin>> err[i];
        }
        cout<< "Enter the element you want to search: ";
        cin>> key;
        for(int i=0;i<5;i++) {
            if(err[i] == key) {
                j=1;
                break;
            }
            }
            if(j==1) {
                cout<< "Key Found";
            }
            else {
                cout<< "Key not found";
            }
        }
    }
