#include <iostream>

using namespace std;

class node {
private:
    int data;
    node *next;
public:
    node(int x) : data(x), next(nullptr) {}


    void setNext(node *node1) {
        next = node1;
    }

    node *getNext() {
        return next;
    }

    [[nodiscard]] int getData() const {
        return data;
    }

    void setData(int x) {
        data = x;
    }
};


class LinkList {
private:
    node *start = nullptr;
public:
    node *nodecreated(int val) {
        node *n, *p;
        n = new node(val);
        n->setNext(nullptr);
        return n;
    }

    void insertFirst() {
        node *n, *p;
        int v;
        cin >> v;
        n = nodecreated(v);
        if (start == nullptr) {
            start = n;
            start->setNext(nullptr);
        } else {
            p = start;
            start = n;
            start->setNext(p);
        }
        cout << "inserted" << endl;
    }

    void insertLast() {
        node *n, *p;
        int val;
        cin >> val;
        n = nodecreated(val);
        p = start;
        while (p->getNext() == nullptr) {
            p = p->getNext();
        }
        n->setNext(nullptr);
        p->setNext(n);
    }

    void insertAfter(int val) {
        node *node = start, *n, *t;
        while (node != nullptr && node->getData() != val) {
            node = node->getNext();
        }
        if (node == nullptr) {
            cout << "there is not such a val" << endl;
            return;
        }
        int v;
        cin >> v;
        n = nodecreated(v);
        t = node->getNext();
        node->setNext(n);
        n->setNext(t);
    }


    void deleteByValue(int val) {
        node *temp = start, *prev = nullptr;
        if (temp != nullptr && temp->getData() == val) {
            start = temp->getNext();
            delete temp;
            return;
        }
        while (temp != nullptr && temp->getData() != val) {
            prev = temp;
            temp = temp->getNext();
        }
        if (temp == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }
        prev->setNext(temp->getNext());
        delete temp;
    }


    void disPlay() {
        node *node = start;
        if (start == nullptr) {
            cout << "linklist is empty" << endl;
        }
        while (node != nullptr) {
            cout << node->getData() << endl;
            node = node->getNext();
        }
    }
};

int main() {
    LinkList a;

    while (1) {
        cout << "1-insert" << endl;
        cout << "2-add last" << endl;
        cout << "3-add first" << endl;
        cout << "4-display" << endl;
        cout << "6-delete" << endl;
        cout << "6-Exit" << endl;

        int x;
        cin >> x;
        switch (x) {
            case 1: {
                int b;
                cin >> b;
                a.insertAfter(b);
                break;
            }
            case 2:
                a.insertLast();
                break;
            case 3:
                a.insertFirst();
                break;
            case 4:
                a.disPlay();
                break;
            case 5:
                int b;
                cin >> b;
                a.deleteByValue(b);
                break;
            case 6:
                exit(1);
                break;
        }

    }

    return 0;
}
