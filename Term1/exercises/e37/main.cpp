#include <iostream>
#include <string>

using namespace std;

int main() {
    int a[5] = {};

    int s = 0, d = 0, max;
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    cout << sizeof(a) / sizeof(string);
    for (int i = 0; i < 5; ++i) {
        max = a[0];
        if (max < a[i]) {
            s = a[i];
            d = i + 1;
        }
    }
    cout << endl << s << "\t" << d;
    return 0;
}
