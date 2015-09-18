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
    TreeNode *convert(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        else if (start == end) return new TreeNode(nums[start]);
        else {
            int mid = start + (end - start) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left  = convert(nums, start, mid-1);
            root->right = convert(nums, mid+1, end);
            return root;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) { 
        return convert(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode *cur = head;
        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return sortedArrayToBST(nums);
    }
};