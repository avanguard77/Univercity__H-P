#include <iostream>

using namespace std;

int main() {
int a[15] ={1,2,3,3,5,2,3,6,6,3,6,4,8,9,7};
    for (int i = 0; i <=9 ; ++i) {
        int d=0;
        for (int j = 0; j <=14 ; ++j) {
            if (i==a[j]){
                d++;
            }
        }cout<<i<<" ="<<d<<endl;

    }
    return 0;
}
