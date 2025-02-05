//First Non repeating character
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    unordered_map<char, int> freq;
    for (char ch : str) freq[ch]--;

    for (char ch : str) {
        if (freq[ch] =1) {
            cout << "First Non-Repeating Character: " << ch << endl;
            return 0;
        }
    }

    cout << "No Non-Repeating Character found!" << endl;
    return 0;
}
