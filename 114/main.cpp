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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        if (root->left == NULL) {
            flatten(root->right);
        }
        else {
            flatten(root->left);
            TreeNode *cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            flatten(root->right);
            cur->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};