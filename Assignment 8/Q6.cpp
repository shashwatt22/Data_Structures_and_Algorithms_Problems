#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int n;
public:
    PriorityQueue() { n = 0; }
    void insert(int x) {
        arr[n] = x;
        int i = n;
        n++;
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void remove() {
        if (n == 0) return;
        arr[0] = arr[n - 1];
        n--;
        int i = 0;
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && arr[l] > arr[largest]) largest = l;
            if (r < n && arr[r] > arr[largest]) largest = r;
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
    }
    void display() {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int ch, x;
    while (1) {
        cout << "1.Insert 2.Remove 3.Display 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; pq.insert(x); break;
            case 2: pq.remove(); break;
            case 3: pq.display(); break;
            case 4: return 0;
        }
    }
}
