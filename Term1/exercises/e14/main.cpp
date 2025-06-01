#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

float f(float a){

    float sum = 0;

    for (float i = 1; i <= a; ++i) {
        sum = sum + 1 / i;

    }
    return sum;
}

int main() {

   float h;
   cin>>h;
   cout<<f(h);

    return 0;
}
