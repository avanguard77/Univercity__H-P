#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int f(int a){
int x;
    x=(((a%3)+2)-a)*2;
    return x;
}


int main() {


    int a, s;/* روش سوم*/
    cin >> a;

    s=f(a);

   /* s=a%3;                   روش اول
     s=s+2;
     s=s-a;
     s=s*2;*/
    cout << s;
    //s=(((a%3)+2)-a)*2;            روش دوم

    return 0;
}
