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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        
        ListNode *remain = swapPairs(head->next->next);
        ListNode *ret = head->next;
        ret->next = head;
        ret->next->next = remain;
        return ret;
    }
};