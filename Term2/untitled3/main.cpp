#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;

    if (a == 1) {
        cout << "1" << endl;
        return 0;
    }
    if (a % 2 == 0 || a % 5 == 0) {
        cout << "-1" << endl;
        return 0;
    }

    int count = 1;
    int remainder = 1 % a;

    while (remainder != 0) {
        remainder = (remainder * 10 + 1) % a;
        count++;
    }

    string repunitStr(count, '1');

    vector<int> repunitNum;
    for (char c : repunitStr) {
        repunitNum.push_back(c - '0');
    }

    vector<int> k;
    int carry = 0;
    for (int digit : repunitNum) {
        int num = carry * 10 + digit;
        k.push_back(num / a);
        carry = num % a;
    }
    bool leadingZero = true;
    for (int digit : k) {
        if (digit != 0 || !leadingZero) {
            cout << digit;
            leadingZero = false;
        }
    }
    cout << endl;

    return 0;
}