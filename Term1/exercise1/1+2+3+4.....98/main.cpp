#include <iostream>

using namespace std;

int main() {
    int sum=0;
    for (int i = 10; i <100 ; i+=2) {
        cout<<i<<endl;
        sum+=i;
    }
    cout<<"sum="<<sum;
    return 0;
}
