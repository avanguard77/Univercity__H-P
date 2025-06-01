#include <iostream>

using namespace std;

int f(int x) {
    int t;
    if (x >= 1) {
        return t = x + f(x - 1);
    }


}

int main() {
    int s;
    cin >> s;
    cout << f(s);
    return 0;
}
