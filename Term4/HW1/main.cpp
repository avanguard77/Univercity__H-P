#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool hasArr(const vector<int> &arr) {
    unordered_set<int> prefixSums;
    int currentSum = 0;

    for (int num: arr) {
        currentSum += num;
        if (currentSum == 0 || prefixSums.find(currentSum) != prefixSums.end()) {
            return true;
        }
        prefixSums.insert(currentSum);
    }

    return false;
}


int main() {
    int t;
    cin >> t;
    vector<int> arr(t);
    for (int i = 0; i < t; ++i) {
        cin >> arr[i];
    }
    if (hasArr(arr)) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }

}
