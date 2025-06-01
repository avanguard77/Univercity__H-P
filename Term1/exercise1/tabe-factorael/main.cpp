#include <iostream>

using namespace std;

int factor(int x){
    int sum=1;
    for (int i = 1; i <=x ; ++i) {
        sum*=i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout<<factor(n);
    return 0;
}
