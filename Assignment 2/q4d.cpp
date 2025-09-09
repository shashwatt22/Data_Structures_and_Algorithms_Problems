#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strings(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }


    sort(strings.begin(), strings.end());

    cout << "Strings in alphabetical order:\n";
    for (const string& str : strings) {
        cout << str << endl;
    }

    return 0;
}
