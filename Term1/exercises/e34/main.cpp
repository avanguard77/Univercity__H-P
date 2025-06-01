#include <iostream>

using namespace std;

int f(int g){
    if (g==0||g==1){
        return 1;
    }return f(g-1)+ f(g-2);
}

int main() {
    int a;
    cin>>a;
    cout<<f(a);
    return 0;
}
