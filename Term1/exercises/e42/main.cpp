#include <iostream>

using namespace std;



int main() {
const int size=6;
    int a[size] = {1, 2, 3, 6, 6, 5};
    int t;
    for (int i = 0; i <size-1 ; ++i) {
        for (int j = 0; j <size-1; ++j) {
            if (a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }

        }cout<<a[i]<<"  ";
    }
    return 0;
}
