#include <iostream>
#include <math.h>


using namespace std;

int main() {
    int ns;
    cout << "number of student?" << endl;
    cin >> ns;
    for (int i = 1; i <= ns; i++) {
        cout << i << "-";
        int sd;
        cin >> sd;
        if (sd >= 10) {
            cout << "pass" << endl;
        } else {
            cout << "fail" << endl;
        }
    }


    return 0;
}
