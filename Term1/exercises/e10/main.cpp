#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int f(int x, int y, int z) {
    if (x > y) {
        if (x > z)
            return x;
    }
        if (y > z) {
            return y;
        } else {
            return z;
        }


}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << f(a, b, c);
    return 0;
}
