#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

float z(int x,int y){
    float v;
    v=(x*x*3.14)*y;
    return v;
}


int main() {
   int r,h;
   cin>>r>>h;
   cout<<z(r,h);
    return 0;
}
