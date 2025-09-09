#include<iostream>
using namespace std;
int main() {
    int sparse[4][3] = {{3, 3, 3}, {0, 0, 1}, {1, 2, 2}, {2, 1, 3}};
    int transpose[100][3];
    int k=1, t=0;
    for(t=0;t<3;t++) {
    for(int i=1;i<4;i++) {
        if(sparse[i][1] == t) {
            transpose[k][0] = sparse[i][1];
            transpose[k][1] = sparse[i][0];
            transpose[k][2] = sparse[i][2];
            k++;
        }
    }
    }
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];
    cout<< "Transpose of a sparse matrix: " <<endl;
    for(int i=0;i<k;i++) {
        for(int j=0;j<3;j++) {
            cout<< transpose[i][j] <<" ";
        }
        cout<<'\n';
    }   
}
