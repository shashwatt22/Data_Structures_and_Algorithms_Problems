#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[200];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
