#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;


float f(int s) {
    return s*s;
}

float h(float x, float u, float y, float z) {

    float r;
    r = sqrt(f(x - y) + f(u - z));
    return r;
}


int main() {
    int a, b, c, d;
    cout << "1 position :" << endl;
    cin >> a >> b;
    cout << "2 position :" << endl;
    cin >> c >> d;
    cout << h(a, b, c, d);
    return 0;
}
