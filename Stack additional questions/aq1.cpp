#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[100], G[100];
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]) {
                found = A[j];
                break;
            }
        }
        G[i] = found;
    }

    for (int i = 0; i < n; i++) cout << G[i] << " ";
    return 0;
}
