#include <iostream>
#include <vector>

int main() {
    int a , b , c;
    std::cin >> a >> b >> c;


    std::vector<std::vector<double>> m1(a, std::vector<double>(b));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            std::cin >> m1[i][j];
        }
    }

    std::vector<std::vector<double>> m2(b, std::vector<double>(c));
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cin >> m2[i][j];
        }
    }

    std::vector<std::vector<double>> m3(a, std::vector<double>(c, 0.0)); // Initialize to zero


    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < b; ++k) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }


    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << m3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
