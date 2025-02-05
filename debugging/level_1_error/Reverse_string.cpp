 // reverse string
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str, reversed = "";
    cout << "Enter a string: ";
    cin >> str;
 for (int i = str.length() - 2; i > 0; i--) {
        reversed += str[i];
    }
        cout << "Reversed String: " << reversed << endl;
    return 0;
}