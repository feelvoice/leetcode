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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int level = 1;
        TreeNode *left = root->left, *right = root->right;
        while (left && right) {
            left = left->left;
            right = right->right;
            level++;
        }
        
        if (left == NULL && right == NULL) {
            return (1 << level) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};