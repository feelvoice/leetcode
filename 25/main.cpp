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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        for (int i=0; i<k; i++) {
            if (cur == NULL) return head;
            cur = cur->next;
        }
        
        ListNode *ret = reverseKGroup(cur, k);
        ListNode *tmp = head;
        for (int i=0; i<k; i++) {
            cur = tmp;
            tmp = tmp->next;
            cur->next = ret;
            ret = cur;
        }
        return ret;
    }
};