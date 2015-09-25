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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        
        int prev;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *cur = q.front(); q.pop();
            if (cur == NULL) {
                ret.push_back(prev);
                if (!q.empty()) q.push(NULL);
            }
            else {
                prev = cur->val;
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return ret;
    }
};