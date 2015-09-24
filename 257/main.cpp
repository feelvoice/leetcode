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

    string format(vector<int> &cur, int val) {
        char buffer[16];
        if (cur.empty()) {
            sprintf(buffer, "%d", val);
            return buffer;
        }
        else {
            string ret;
            for (int i=0; i<cur.size(); i++) {
                sprintf(buffer, "%d->", cur[i]);
                ret += buffer;
            }
            sprintf(buffer, "%d", val);
            ret += buffer;
            return ret;
        }
    }

    void dfs(TreeNode* root, vector<int> &cur, vector<string> &ret) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(format(cur, root->val));
            return;
        }
        
        cur.push_back(root->val);
        if (root->left == NULL) {
            dfs(root->right, cur, ret);
        }
        else if (root->right == NULL) {
            dfs(root->left, cur, ret);
        }
        else {
            dfs(root->left, cur, ret);
            dfs(root->right, cur, ret);
        }
        cur.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> cur;
        dfs(root, cur, ret);
        return ret;
    }
};