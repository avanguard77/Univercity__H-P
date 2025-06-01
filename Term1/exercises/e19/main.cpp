#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

float h(int q, int w) {
    float g = 1;
    for (int i = 1; i <= w; ++i) {
        g *= q;

    }
    return g;
}

float f(int x, int y) {
    float a = 3 * x + y;
    return h(x, y) / h(a, 2);
}

int main() {

    //   f(a,b)=(a^b)/((a+3b))^2)

    int a, b;
    cin >> a >> b;
cout<<f(a,b);

    return 0;
}



