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

    int single_path_sum(TreeNode *root, int &ret) {
        if (root == NULL) return 0;
        
        int left  = single_path_sum(root->left, ret);
        int right = single_path_sum(root->right, ret);
        ret = max(ret, root->val);
        ret = max(ret, root->val + left);
        ret = max(ret, root->val + right);
        ret = max(ret, root->val + left + right);
        return root->val + max(max(left, right), 0);
    }

    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        single_path_sum(root, ret);
        return ret;
    }
};