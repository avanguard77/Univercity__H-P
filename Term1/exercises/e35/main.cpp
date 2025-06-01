#include <iostream>

using namespace std;

int main() {
    int a[7] = {};
    int i = 0, d = 0;
    for (; i <= 6; ++i) {
        cin >> a[i];


    }

    for (int j = 0; j <7 ; ++j) {

        if (a[j] < 0) {
            cout << a[j] << endl;
            d++;
        }
    }


    cout << d;

    return 0;
}
