#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class LinkList {
private:
    Node* start = nullptr;
public:
    void insertByNumber(char a, int l) {
        Node* n = new Node;
        n->data = a;
        n->next = nullptr;

        if (start == nullptr || l == 0) {
            n->next = start;
            start = n;
            return;
        }

        Node* p = start;
        for (int i = 0; i < l - 1 && p->next != nullptr; ++i) {
            p = p->next;
        }

        n->next = p->next;
        p->next = n;
    }

    void display() const {
        if (start == nullptr) {
            cout << "Linklist is empty" << endl;
            return;
        }

        Node* node = start;
        while (node != nullptr) {
            cout << node->data;
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    LinkList a;
    int n, k = 0,kadded=0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string m;
        cin >> m;

        if (m == "+") {
            if (kadded>=k)
            k++;

        } else if (m == "-") {
            if (kadded>0)
            k--;
        } else {
            char lastChar ;
            kadded++;
            cin>>lastChar;
            a.insertByNumber(lastChar, k++);
        }
    }
    a.display();

    return 0;
}
