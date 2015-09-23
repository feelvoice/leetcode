/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ret = NULL, *prev = NULL;
        ListNode *cur = head;
        
        while (cur) {
            if (cur->val == val) {
                if (prev) {
                    prev->next = cur->next;
                }
            }
            else {
                if (ret == NULL) ret = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        return ret;
    }
};