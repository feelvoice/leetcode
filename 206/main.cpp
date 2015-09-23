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
    ListNode* reverseList(ListNode* head) {
        ListNode *ret = NULL, *tmp;
        ListNode *cur = head;
        
        while (cur) {
            tmp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = tmp;
        }
        return ret;
    }
};