#include <iostream>

using namespace std;

int main() {
    int n, i = 0;
    cin >> n;
    while (n != 0) {
        i = i * 10;
        i = i + n % 10;
        n = n / 10;
    }
    cout << i;
    // v have n , i
    for (;;) {
        if (i % 10 == n % 10) {
            i = i / 10;
            n = n / 10;
            if (i != 0) {
                cout << "right";
                break;
            } else {
                cout<<"wrong";
                break;
            }

        }


    }

    return 0;
}
