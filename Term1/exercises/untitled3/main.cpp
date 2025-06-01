#include <iostream>

using namespace std;

bool bb(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }
    if (sum % 3 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int num;
    cout << "entr your num: ";
    cin >> num;
    if (bb(num)) {
        cout << num << " yes" << endl;
    } else {
        cout << num << " no" << endl;
    }
    return 0;
}