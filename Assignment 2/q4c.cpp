#include <iostream>
using namespace std;

bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        return true;
    }
    return false;
}

int main() {
    string str, result;
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (!isVowel(str[i])) {
            result += str[i];
        }
    }

    cout << "String after deleting vowels: " << result << endl;
    return 0;
}
