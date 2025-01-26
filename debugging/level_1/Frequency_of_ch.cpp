#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    unordered_map<char, int> freq;
    for (char ch : str) freq[ch]++;

    cout << "Character Frequencies:" << endl;
    for (auto pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
