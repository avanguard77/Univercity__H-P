#include <iostream>

using namespace std;

int main() {
    int a, f = 1;
    cin >> a;
    for (int i = 1; i <= a; ++i) {
        f = f * i;
    }
    cout << "factorial :" << f << endl;
    cout<<"e =";

    for (float i = 1; i <= a; ++i) {
        f = f * i;
        float h=i/f;
        cout<<h<<"+";

    }
    return 0;
}
