#include <iostream>
#include <string>
using namespace std;
bool containsM(string& input) {
    for (char c : input) {
        if (c == 'm' || c == 'M') {
            return true;
        }
    }
    return false;
}

int main() {
    string input;
    cin>>input;
    if(!containsM(input)){
        cout<<"true";
    }else{
        cout<<"false";
    }


    return 0;
}
