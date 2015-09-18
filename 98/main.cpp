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

    int mymax(TreeNode *root) {
        TreeNode *cur = root;
        int ret;
        while (cur) {
            ret = cur->val;
            cur = cur->right;
        }
        return ret;
    }
    
    int mymin(TreeNode *root) {
        TreeNode *cur = root;
        int ret;
        while (cur) {
            ret = cur->val;
            cur = cur->left;
        }
        return ret;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left) {
            int left  = mymax(root->left);
            if (left >= root->val) return false;
        }
        if (root->right) {
            int right = mymin(root->right);
            if (right <= root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right); 
    }
};