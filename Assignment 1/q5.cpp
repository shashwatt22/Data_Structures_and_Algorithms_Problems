#include<iostream>
using namespace std;
int main() {
    int i,j,rows,cols;
    cout<< "Enter the number of rows and columns: ";
    cin>> rows >> cols;
    int arr[rows][cols];
    cout<< "Enter the elements of an array: ";
    for( i=0;i<rows;i++) {
        for( j=0;j<cols;j++) {
            cin>> arr[i][j];
        }
    }
    //sum of every row
    for(i=0;i<rows;i++) {
        int rowSum = 0;
        for( j=0;j<cols;j++) {
            rowSum = rowSum + arr[i][j];
        }
        cout<< "The sum of row " <<i+1<< " is "<< rowSum << endl;  
    }
    //sum of every column
    for( i=0;i<rows;i++) {
        int colsSum = 0;
        for( j=0;j<cols;j++) {
            colsSum = colsSum + arr[j][i];
        }
        cout<< "The sum of column " <<i+1<< " is "<< colsSum << endl;  
    }
return 0;
}
