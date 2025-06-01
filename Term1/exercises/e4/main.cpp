#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;


int f(int b) {
    int s=b%2;
    return s;
}


int main() {
    int a;
    cin >> a;
    if (f(a)==1) {
        cout << "yes";

    }
    if (f(a)==0) {
        cout << "no";
    }


    return 0;
}
