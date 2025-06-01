#include <iostream>

using namespace std;
struct node {
    int val;
    node *right;
    node *left;
    int hieght;
};

node *create(int data) {
    node *n = new node;
    n->val = data;
    n->left = nullptr;
    n->right = nullptr;
    n->hieght = 1;
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

int height(node *n) {
    if (n == nullptr) {
        return 0;
    }
    return n->hieght;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

node *addAVL(node *n, int k) {
    if (n == nullptr) {
        return create(k);
    }
    if (k < n->val) {
        n->left = addAVL(n->left, k);
    } else if (k > n->val) {
        n->right = addAVL(n->right, k);
    } else {
        return n;
    }
}

int main() {

}
