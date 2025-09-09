#include<iostream>
using namespace std;
int main() {
    int rows,cols;
    cout<< "Enter the number of rows and columns: ";
    cin>> rows >> cols;
    int arr[rows][cols];
    cout<< "Enter the elements of an array: ";
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cin>> arr[i][j];
        }
    }
        for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout<< arr[i][j] <<" ";
        }
        cout<<'\n';
    }
    cout<< "The transported array is: \n";
    for(int i=0;i<cols;i++) {
        for(int j=0;j<rows;j++) {
            cout<< arr[j][i] <<" ";
        }
        cout<<'\n';
    }
}
