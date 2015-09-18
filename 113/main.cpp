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

    void path_sum(TreeNode* root, int sum, vector<int> &cur, vector<vector<int> > &ret) {
        if (root == NULL) return;
        
        cur.push_back(root->val);
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            ret.push_back(cur);
        }
        if (root->left == NULL) {
            path_sum(root->right, sum-root->val, cur, ret);
        }
        else if (root->right == NULL) {
            path_sum(root->left, sum-root->val, cur, ret);
        }
        else {
            path_sum(root->left, sum-root->val, cur, ret);
            path_sum(root->right, sum-root->val, cur, ret);  
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur;
        vector<vector<int> > ret;
        
        path_sum(root, sum, cur, ret);
        return ret;
    }
};