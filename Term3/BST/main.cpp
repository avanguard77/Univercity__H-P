#include <iostream>

using namespace std;
struct node {
    int val;
    node *right;
    node *left;
};

node *create(int data) {
    node *n = new node;
    n->val = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

node *insert(node *n, int val) {
    if (n == nullptr) {
        return create(val);
    } else if (val < n->val) {
        n->left = insert(n->left, val);
    } else if (n->val < val) {
        n->right = insert(n->right, val);
    }
    return n;
}

node *serch(node *n, int k) {
    if (n == nullptr || k == n->val) {
        return n;
    } else if (n->val < k) {
        return serch(n->right, k);
    } else if (n->val > k) {
        return serch(n->left, k);
    }

}

void preorder(node *n) {
    if (n != nullptr) {
        cout << n->val << "\t";
        preorder(n->left);
        preorder(n->right);
    }
}

node *minn(node *n) {
    if (n== nullptr||n->left == nullptr) {
        return n;
    }
    minn(n->left);

}

node *remove(node *r, int k) {
    node *t;
    if (r == nullptr) {
        return r;
    }
    if (k < r->val) {
        r->left = remove(r->left, k);
    } else if (k > r->val) {
        r->right = remove(r->right, k);
    } else {
        if (r->left == nullptr) {
            t = r->right;
            delete r;
            return t;
        } else if (r->right == nullptr) {
            t = r->left;
            delete r;
            return t;
        }
        t = minn(r->right);
        r->val = t->val;
        r->right = remove(r->right, r->val);
    }
    return r;

}

int main() {
    node *n = nullptr;
    n = insert(n, 5);
    insert(n, 7);
    insert(n, 6);
    insert(n, 4);
    insert(n, 3);
    insert(n, 1);


    preorder(n);
    remove(n,5);
    cout<<endl;
    preorder(n);

}
