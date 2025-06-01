#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int main() {
   int a,b;
   char ch;
   cin>>a>>b;
   cout<<"what do u want to do ??";
   cin>>ch;
    if (ch=='+')
        cout<<a<<"+"<<b<<"="<<a+b;
    if (ch=='-')
        cout<<a<<"-"<<b<<"="<<a-b;
    if (ch=='*')
        cout<<a<<"*"<<b<<"="<<a*b;
    if (ch=='/')
        cout<<a<<"/"<<b<<"="<<a/b;


    return 0;
}
