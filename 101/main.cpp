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

    bool is_mirror(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL || q == NULL) return false;
        return p->val == q->val && is_mirror(p->left, q->right) && is_mirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return is_mirror(root->left, root->right);
    }
};