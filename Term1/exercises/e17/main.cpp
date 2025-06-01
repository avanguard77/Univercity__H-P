#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

float f(float x) {


    float c =1, d = 0, z, y=1, a=1;
    int i = 1;

    do {
        i++;
        if (x >= i) {
            z = y / a;

        }
        if (i % 2 == 0) {
            d += 2;
            y = y * d;
        }
        if (i % 2 == 1) {
            c += 2;
            a = a * c;
        }


    } while (x >= i);

    return z;
}


int main() {
    int a;
    cin >> a;
    cout << f(a);
    return 0;
}
