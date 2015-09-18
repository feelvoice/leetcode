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

    TreeNode *build(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij) {
        if (pi > pj) {
            return NULL;
        }
        else if (pi == pj) {
            return new TreeNode(preorder[pi]);
        }
        else {
            TreeNode *root = new TreeNode(preorder[pi]);
            int rooti;
            for (rooti=ii; rooti<=ij; rooti++) {
                if (inorder[rooti] == preorder[pi]) {
                    break;
                }
            }
            int left = rooti - ii;
            root->left  = build(preorder, pi+1, pi+left, inorder, ii, rooti-1);
            root->right = build(preorder, pi+left+1, pj, inorder, rooti+1, ij);
            return root;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};