#include <iostream>
using namespace std;

// تابع برای چاپ مثلث خیام پاسکال
void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        int value = 1; // عدد اول هر سطر همیشه 1 است
        for (int i = 0; i <= line; i++) {
            cout << value << " ";
            value = value * (line - i) / (i + 1);
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    printPascal(n);
    return 0;
}
