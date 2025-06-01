#include <iostream>
using namespace std;

int main() {
    /*int b = 0;
    int *p = &b;
    cout << p << endl << *p<<endl;

    int f = 5;
    int const *pf = &f;
    pf=&b;
    cout<<*pf;

    int g=8;
    int * const pg=&g;
    *pg=5;
    */
    /*int a[] = {1, 5, 6, 4, 6};
    int *p = a + 4;
    for (int i = 0; i < 5; i++) {
        cout << *p << endl;
        p--;
    }*/
    /*cout<<endl<<endl;
    int p=5;
    int *pn=&p;
    cout<<*pn<<endl<<p;*/
    int a[2][3]={{1,2,3},{5,6,7}};
    int (*p)[3]=a;

}
