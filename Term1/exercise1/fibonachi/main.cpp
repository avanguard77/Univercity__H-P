#include <iostream>

using namespace std;

int main() {

    int num, f1 = 0, f2 = 1, temp;
    cin >> num;
    for (int i = 1; i <= num; ++i) {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;

    }
    cout << f2;
    return 0;
}
