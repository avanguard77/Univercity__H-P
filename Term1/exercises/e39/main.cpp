#include <iostream>

using namespace std;

void f(int s[], int d) {


    if (d>=0){
        cout<<s[d];
    }
    f(s, d - 1);


}

int main() {
    int a[3] = {3, 4, 5};
    f(a, 2);
    return 0;
}
