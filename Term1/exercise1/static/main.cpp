#include <iostream>

using namespace std;

void f();

void y();

int main() {

    f();
    f();
    f();
    y();
    y();
    y();
    return 0;
}

void f() {
    static int x = 1;
    ++x;
    cout << x << endl;

}

void y() {
    int x = 1;
    ++x;
    cout << x << endl;

}