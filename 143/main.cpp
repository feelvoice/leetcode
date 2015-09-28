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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode *fast = head, *slow = head, *mid, *tmp, *tmp2;
        do {
            if (fast->next == NULL || fast->next->next == NULL) {
                mid = slow->next;
                slow->next = NULL;
                break;
            }
            else {
                fast = fast->next->next;
                slow = slow->next;
            }
        } while (1);
        ListNode *rev = NULL, *cur = mid, *cur2;
        while (cur) {
            tmp = cur->next;
            cur->next = rev;
            rev = cur;
            cur = tmp;
        }
        
        cur = head;
        cur2 = rev;
        while (cur) {
            tmp = cur->next;
            if (cur2) tmp2 = cur2->next;
            cur->next = cur2;
            if (cur2) cur2->next = tmp;
            cur = tmp;
            cur2 = tmp2;
        }
    }
};