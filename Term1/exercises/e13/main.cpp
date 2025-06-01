#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (; t < 0;) {


        if (t%2 == 1) {
            cout << "1";
        }
        if (t%2 == 0) {
            cout << "0";
        }
        t = t / 2;
    }


    return 0;
}
