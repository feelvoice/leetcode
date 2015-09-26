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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        for (int i=0; i<n; i++) {
            first = first->next;
        }
        
        ListNode* second = head;
        ListNode* prev = NULL;
        while (first) {
            first = first->next;
            prev = second;
            second = second->next;
        }
        
        if (!prev) {
            return second->next;
        }
        prev->next = second->next;
        return head;
    }
};