#include <iostream>

using namespace std;

template<class T, class H>
T f(T d[]) {



}

int main() {
    int s[10] = {},max=s[0];
    for (int i = 0; i <10 ; ++i) {
        cin>>s[i];
        if (s[i]==0){
            break;
        }
        if (max<s[i]){
            max=s[i];
        }
    }cout<<max;
    return 0;
}

