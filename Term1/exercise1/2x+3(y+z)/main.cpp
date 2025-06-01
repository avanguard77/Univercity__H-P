#include <iostream>

using namespace std;

int f(int x, int y, int z) {
    return  (2*x+3*(y+z));
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << f(x, y, z);
    return 0;
}
