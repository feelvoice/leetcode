#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> ret;
        if (start > end) {
            ret.push_back(NULL);
            return ret;
        }
        
        for (int k=start; k<=end; k++) {
            vector<TreeNode*> left  = generate(start, k-1);
            vector<TreeNode*> right = generate(k+1, end);
            for (int i=0; i<left.size(); i++) {
                for (int j=0; j<right.size(); j++) {
                    TreeNode *node = new TreeNode(k);//.......
                    node->left = left[i];
                    node->right = right[j];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};

void inorder(TreeNode *root) {
    if (root == NULL) return;
    cout << root->val << ' ';
    inorder(root->left);
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

int main()
{
    Solution s = Solution();
    vector<TreeNode*> ret = s.generateTrees(4);
    for (int i=0; i<ret.size(); i++) {
        inorder(ret[i]);
        cout << " | ";
        postorder(ret[i]);
        cout << endl;
    }
    
    return 0;
}
