#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }

    void postOrderTraversal(TreeNode* node, vector<int>& postorder) {
        if (node != NULL) {
            postOrderTraversal(node->left, postorder);
            postOrderTraversal(node->right, postorder);
            postorder.push_back(node->val);
        }
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorder_map) {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorder_map);
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorder_map);

        return root;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n);
    vector<int> preorder(n);

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    vector<int> postorder;
    solution.postOrderTraversal(root, postorder);

    for (int i = 0; i < postorder.size(); ++i) {
        cout << postorder[i] << " ";
    }
    cout << endl;

    return 0;
}

