#include <iostream>
#include <math.h>
using namespace std;

int main() {

    int a, b, c;

    cin >> a >> b >> c;

    int min, mid, max;


    if (a < b && a < c) {
        min = a;
        if (b < c) {
            mid = b;
            max = c;
        } else {
            mid = c;
            max = b;
        }
    } else if (b < a && b < c) {
        min = b;
        if (a < c) {
            mid = a;
            max = c;
        } else {
            mid = c;
            max = a;
        }
    } else {
        min = c;
        if (a < b) {
            mid = a;
            max = b;
        } else {
            mid = b;
            max = a;
        }
    }
    cout << min << " " << mid << " " << max << endl;
    return 0;
}