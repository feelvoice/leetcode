/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void inorder_traversal(TreeNode *root, vector<int> &ret) {
        if (root == NULL) return;
        inorder_traversal(root->left, ret);
        ret.push_back(root->val);
        inorder_traversal(root->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder_traversal(root, ret);
        return ret;
    }
};