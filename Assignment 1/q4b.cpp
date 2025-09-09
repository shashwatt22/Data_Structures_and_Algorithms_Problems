#include<iostream>
using namespace std;
int main() {
    int rows1,cols1,rows2,cols2;
    cout<< "Enter the rows and columns of the first matrix: ";
    cin>> rows1 >> cols1;
    cout<< "Enter the rows and columns of the second matrix: ";
    cin>> rows2>> cols2;
    if(cols1 != rows2) {
        cout<< "Matrix multiplication not possible."<< endl;
    }
    else {
        int a[rows1][cols1], b[rows2][cols2], result[rows1][cols2];
        cout<< "Enter the elements of the first matrix:";
        for(int i=0;i<rows1;i++) {
            for(int j=0;j<cols1;j++) {
                cin>> a[i][j];
            }
        }
        cout<< "Enter the elements of the second matrix:";
        for(int i=0;i<rows2;i++) {
            for(int j=0;j<cols2;j++) {
                cin>> b[i][j];
            }
        }
        for(int i=0;i<rows1;i++) {
            for(int j=0;j<cols2;j++) {
                int sum = 0;
                for(int k=0;k<cols1;k++) {
                    sum = sum + (a[i][k] * b[k][j]);
                }
                result[i][j] = sum;
            }
        }
        cout<< "The resultant matrix is: \n";
        for(int i=0;i<rows1;i++) {
            for(int j=0;j<cols2;j++) {
                cout<< result[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}
