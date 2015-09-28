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
    bool hasCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        do {
            if (first == NULL || first->next == NULL) return false;
            if (second == NULL || second->next == NULL || second->next->next == NULL) return false;
            first = first->next;
            second = second->next->next;
            if (first == second) return true;
        } while (1);
    }
};