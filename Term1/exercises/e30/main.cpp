#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    int d = a - 1;
    for (int i = 0; i <= a; ++i) {

        for (int j = 0; j <= d; ++j) {
            cout << " ";
        }
        d--;
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << "x";
        }
        cout << endl;
    }
    int s = 0;
    for (int i = a - 1; i >= 0; i--) {
        for (int j = 0; j <= s; ++j) {
            cout << " ";
        }
        s++;
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << "x";
        }
        cout << endl;
    }


    return 0;
}
