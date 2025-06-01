#include <iostream>

using namespace std;

class node {
private:
    int data;
    node *next;
    node *perv;
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

    void setPerv(node *p) {
        this->perv = p;
    }

    node *getPerv() {
        return perv;
    }

};


class LinkListDo {
private:
    node *start = nullptr;
public:
    void nodeCreated() {
        int val;
        cin >> val;
        node *n, *p;
        n = new node(val);
        n->setNext(nullptr);
        if (start == nullptr) {
            n->setPerv(nullptr);
            start = n;
        } else {
            p = start;
            while (p->getNext() != nullptr) {
                p = p->getNext();
            }
            n->setNext(p);
            p->setPerv(n);
        }
    }

    void insertFirst() {
        node *n, *p;
        int v;
        cin >> v;
        n = new(nothrow) node(v);
        if (n == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }
        if (start == nullptr) {
            start = n;
            start->setNext(nullptr);
            start->setPerv(nullptr);
        } else {
            p = start;
            start = n;
            start->setNext(p);
            start->setPerv(nullptr);
        }
        cout << "inserted" << endl;
    }

    void insertAfter(int val) {
        node *nod = start, *n;
        while (nod != nullptr && nod->getData() != val) {
            nod = nod->getNext();
        }
        if (nod == nullptr) {
            cout << "there is not such a val" << endl;
            return;
        }
        int v;
        cin>>v;
        n=new node(v);
        n->setNext(nod->getNext());
        nod->setNext(n);
        n->setPerv(nod);
        n->getNext()->setPerv(n);
        cout << "added " << endl;
    }
    void deleteByValue(int val) {
        node *temp = start, *prev = nullptr;

        // Check if the node to be deleted is the head node
        if (temp != nullptr && temp->getData() == val) {
            start = temp->getNext(); // Change head
            if (start != nullptr) {
                start->setPerv(nullptr); // Update prev of new head to null
            }
            delete temp; // Free the old head
            return;
        }

        // Search for the node to be deleted, keep track of the previous node
        while (temp != nullptr && temp->getData() != val) {
            prev = temp;
            temp = temp->getNext();
        }

        // If the value was not present in linked list
        if (temp == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->setNext(temp->getNext());

        // Update the previous pointer of the next node, if it exists
        if (temp->getNext() != nullptr) {
            temp->getNext()->setPerv(prev);
        }

        delete temp; // Free the memory
    }


    void disPlay() {
        node *node = start;
        if (start == nullptr) {
            cout << "linklist is empty" << endl;
            return;
        }
        cout << "the node is :" << endl;
        while (node != nullptr) {
            cout << "       the node is: " << node->getData() << endl;
            node = node->getNext();
        }
    }
};

int main() {
    LinkListDo a;
    while (1) {
        cout << "1-insert after by value //" << endl;
        cout << "2-add last O" << endl;
        cout << "3-add first 0" << endl;
        cout << "4-display 0" << endl;
        cout << "5-delete 0" << endl;
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
                a.nodeCreated();
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