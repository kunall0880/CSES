#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Declare an array of appropriate size
    int a[n];

    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    // Sorting the array in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    int c = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != c) {
            cout << c;
            break;
        }
        c++;
    }

    return 0;
}
