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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *tail = headA;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = headB;
        
        ListNode *fast = headA, *slow = headA;
        do {
            if (fast->next == NULL || fast->next->next == NULL) {
                tail->next = NULL;
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = headA;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                tail->next = NULL;
                return fast;
            }
        } while (1);
        
    }
};