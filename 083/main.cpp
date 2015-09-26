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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *cur = head;
        while (cur && cur->val == head->val) {
            cur = cur->next;
        }
        head->next = deleteDuplicates(cur);
        return head;
    }
};