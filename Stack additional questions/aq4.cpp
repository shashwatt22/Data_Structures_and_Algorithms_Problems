#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp[200], ans[200];
    for (int i = 0; i < n; i++) cin >> temp[i];

    for (int i = 0; i < n; i++) {
        int days = 0;
        for (int j = i + 1; j < n; j++) {
            if (temp[j] > temp[i]) {
                days = j - i;
                break;
            }
        }
        ans[i] = days;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
