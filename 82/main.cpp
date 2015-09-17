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
        if (head->val == head->next->val) {
            ListNode *cur = head;
            int v = head->val;
            while (cur && cur->val == v) {
                cur = cur->next;
            }
            return deleteDuplicates(cur);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};