#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int f(int x, int y) {
    return x + y;
}


int main() {
    int a, b;
    cin >> a >> b;

    cout<<f(a, b);;
    return 0;
}
