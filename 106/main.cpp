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

    TreeNode *build(vector<int>& inorder, int ii, int ij, vector<int>& postorder, int pi, int pj) {
        if (ii > ij) {
            return NULL;
        }
        else if (ii == ij) {
            return new TreeNode(postorder[pj]);
        }
        else {
            TreeNode *root = new TreeNode(postorder[pj]);
            int rooti;
            for (rooti=ii; rooti<=ij; rooti++) {
                if (inorder[rooti] == postorder[pj]) {
                    break;
                }
            }
            int left = rooti - ii;
            root->left  = build(inorder, ii, rooti-1, postorder, pi, pi+left-1);
            root->right = build(inorder, rooti+1, ij, postorder, pi+left, pj-1);
            return root;
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};