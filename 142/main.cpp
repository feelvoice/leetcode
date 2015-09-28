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
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        do {
            if (first == NULL || first->next == NULL) return NULL;
            if (second == NULL || second->next == NULL || second->next->next == NULL) return NULL;
            first = first->next;
            second = second->next->next;
            if (first == second) {
                first = head;
                while (first != second) {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        } while (1);
    }
};