#include <iostream>

using namespace std;

bool i (int t){
    for (int i = 2; i <= t/ 2; ++i) {
        if (t % i == 0) {

            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int j = 2; j <=n ; ++j) {
        if (i(j)){
            cout<<j<<endl;
        }
    }


    return 0;
}

