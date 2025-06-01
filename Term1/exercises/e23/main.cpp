#include <iostream>

using namespace std;

int main() {
    int a;
    for (; ; ) {
        cin>>a;
        if (a>=90){
            cout<<"A";
        }
        if (89>a&&a>80){
            cout<<"B";
        }
        if (79>a&&a>70){
            cout<<"C";
        } if (69>a&&a>60){
            cout<<"D";
        } if (a<59){
            cout<<"e";
        }
    }
    return 0;
}
