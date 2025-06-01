#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    unordered_set<int> landing_spots;

    for(int i = 0; i < q; ++i) {
        int spot;
        cin >> spot;
        bool granted = true;

        for(int j = spot - k + 1; j < spot + k; ++j) {
            if(landing_spots.find(j) != landing_spots.end()) {
                granted = false;
                break;
            }
        }

        if(granted) {
            cout << "Permission Granted!" << endl;
            landing_spots.insert(spot);
        } else {
            cout << "Permission Denied!" << endl;
        }
    }
    return 0;
}
