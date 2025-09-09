#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100], nge[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int next = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];
                break;
            }
        }
        nge[i] = next;
    }

    for (int i = 0; i < n; i++) cout << nge[i] << " ";
    return 0;
}
