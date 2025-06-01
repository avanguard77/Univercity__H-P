#include <iostream>
using namespace std;

bool f(int );
int main() {
    int i, n;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> n;


    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int j =2; j <=n ; ++j)
        {
            if(f(j))
            {
                cout<<j<<endl;
            }
        }

    }

    return 0;

}
bool f(int n){

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false ;
        }
    }

    return true;
}