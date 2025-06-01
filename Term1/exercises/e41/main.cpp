#include <iostream>

using namespace std;

void mean(int [], int);

void fmod(int  [], int);

void sort(int [], int);

void fmeanane(int [], int);

int main() {
    const int size = 15;
    int a[size] = {1, 2, 3, 1, 2, 8, 4, 6, 2, 3, 5, 6, 9, 6, 6};


    mean(a, size);


    sort(a, size);


    fmeanane(a, size);


    fmod(a, size);


    return 0;
}

void mean(int array[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += array[i];
    }
    cout << static_cast<double >(sum) / len << endl << endl;
}

void fmod(int array[], int len) {
    for (int i = 0; i < 10; ++i) {
        int c = 0;
        for (int j = 0; j < len; ++j) {
            if (array[j] == i) {
                c++;
            }
        }
        cout << i << " :" << c << endl;
    }
}

void sort(int array[], int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            int temp;
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        cout << " " << array[i];

    }

}

void fmeanane(int array[], int len) {

    cout << endl << endl << array[(len / 2) ] << endl << endl;
}
