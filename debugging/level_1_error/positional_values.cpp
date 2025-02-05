//print positional values of an integer
#include <iostream>
using namespace std;

void printPositionalValues(int num) {
    int position = 1;
    while (num / position >= 10) 
       position *= 10;

    while (position > 0) {
        cout << num / (position* position) << endl;
        num %= position;
        position /= 10;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Positional Values:" << endl;
    printPositionalValues(num);

    return 0;
}
