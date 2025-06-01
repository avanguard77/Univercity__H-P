#include <iostream>

using namespace std;

int main() {
    int a;
    char ch = 'a';
    for (; ch<='z'; ch++) {

        a = ch;
        cout << ch<<"="<<a <<"\n";
    }

    return 0;
}
