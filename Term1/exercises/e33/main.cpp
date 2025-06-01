#include <iostream>

using namespace std;

int f(int s, int h) {
    int sum = 0;
    if (h <= 1)
        return s;
        return s *f(s, h - 1);

}

int main() {
    int a, b;
    cin >> a >> b;
    cout << f(a, b);
    return 0;
}
