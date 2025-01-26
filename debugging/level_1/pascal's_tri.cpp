#include <iostream>
using namespace std;

void printPascalsTriangle(int n) {
    for (int i = 0; i < n; i++) {
        int value = 1;
        for (int j = 0; j <= i; j++) {
            cout << value << " ";
            value = value * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    printPascalsTriangle(n);
    return 0;
}
