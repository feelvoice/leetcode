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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }
        if (len == 0) return NULL;
        k %= len;
        if (k == 0) return head;
        
        ListNode *first = head;
        ListNode *second = head;
        for (int i=0; i<k; i++) first = first->next;
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        
        first->next = head;
        ListNode *ret = second->next;
        second->next = NULL;
        return ret;
    }
};