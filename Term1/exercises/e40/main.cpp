#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "1 - login" << endl << "2 - exit" << endl << endl << "choose (1/2)" << endl;
    int q;
    cin >> q;
    if (q == 1) {
        cout << "welcome" << endl << "pls enter u name and password  : ";
        string username;
        int password;
        int ps = 1234;
        cin >> username;
        cout << endl;
        int c = 0;
        for (int i = 3; i >= 0; --i) {
            cin >> password;
            if (ps == password) {
                c++;

                break;
            } else if (ps != password) {
                cout << "wrong password " << endl << "u have " << i << "chanse" << endl;
            }


        }
        int desicion;

        if (c == 1) {
            cout << "welcome again " << username;
            cout << endl << endl << "1-check balance" << endl;
            cout << endl << "2-make dospit" << endl;
            cout << endl << "3-withdrew funds" << endl;
            cout << endl << "4-log out" << endl;

            int account = 1000;
            for (;;) {

                cin >> desicion;
                if (desicion == 1) {
                    cout << "u account balance is " << account << endl;
                } else if (desicion == 2) {
                    int depite;
                    cin >> depite;
                    account += depite;
                    cout << "u account balace is" << account << endl << "done"<<endl;

                } else if (desicion == 3) {
                    int with;
                    cin >> with;
                    account -= with;
                    cout << "u account balace is" << account << endl << "done"<<endl;

                } else if (desicion == 4) {
                    char ch;
                    cout << "do u want to end process??(y/n)  " << endl;
                    cin >> ch;
                    if (ch == 'y') {
                        cout << "process is ended"<<endl;
                        break;
                    } else if (ch == 'n') {
                        cout << "return to process" << endl;
                    }


                }

            }
        } else {
            cout << "u are banned!!!!";
        }


    } else if (q == 2) {
        cout << "bye";
    } else {
        cout << "wrong command";
    }
    return 0;
}
