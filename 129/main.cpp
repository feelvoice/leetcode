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

    int sum_number(TreeNode *root, int cur) {
        if (root == NULL) return 0;
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) return cur;
        else if (root->left == NULL)  return sum_number(root->right, cur);
        else if (root->right == NULL) return sum_number(root->left, cur);
        else return sum_number(root->left, cur) + sum_number(root->right, cur);
    }

    int sumNumbers(TreeNode* root) {
        int cur = 0;
        return sum_number(root, cur);
    }
};