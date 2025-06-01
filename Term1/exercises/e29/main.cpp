#include <iostream>

using namespace std;

int main() {
    int a;
    cin>>a; int d=a-1;
    for (int i = a; i != 0; i--) {

        for (int j = 0; j <=d-a ; ++j) {
            cout<<" ";

        } d++;

        for (int j = 1; j <= i; j++) {
            cout << "x";
        }
        cout<<endl;
    }
    return 0;
}
