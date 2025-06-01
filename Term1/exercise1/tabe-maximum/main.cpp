#include <iostream>

using namespace std;

int max (int x,int y,int z){
    int m=x;
    if (m<y){
        m=y;
    }
    if (m<z){
        m=z;
    }
    return m;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout<<max(a,b,c);
    return 0;
}
