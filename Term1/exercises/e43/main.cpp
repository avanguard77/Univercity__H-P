#include <iostream>

using namespace std;

bool bb(int n) {
    int s = 0;
    while (n > 0) {
        int d = n % 10;
        s += d;
        n /= 10;
    }
    if (s % 3 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cout << "entr your num: ";
    cin >> n;
    if (bb(n)) {
        cout << n << " yes" << endl;
    } else {
        cout << n << " no" << endl;
    }
    return 0;
}
