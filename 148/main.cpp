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

    ListNode *merge(ListNode *n1, ListNode *n2) {
        if (n1 == NULL)  return n2;
        else if (n2 == NULL) return n1;

        ListNode *cur1 = n1, *cur2 = n2;
        ListNode *ret = NULL, *tmp, *tail = NULL;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                if (ret == NULL) ret = cur1;
                if (tail) {
                    tail->next = cur1;
                    tail = tail->next;
                }
                else tail = cur1;
                cur1 = cur1->next;
            }
            else {
                if (ret == NULL) ret = cur2;
                if (tail) {
                    tail->next = cur2;
                    tail = tail->next;
                }
                else tail = cur2;
                cur2 = cur2->next;
            }
        }
        if (cur1) tail->next = cur1;
        else if (cur2) tail->next = cur2;
        else tail->next = NULL;
        return ret;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *fast = head, *slow = head, *n1 = head, *n2 = NULL;
        do {
            if (fast->next == NULL || fast->next->next == NULL) {
                n2 = slow->next;
                slow->next = NULL;
                break;
            }
            else {
                fast = fast->next->next;
                slow = slow->next;
            }
        } while (1);
        
        n1 = sortList(n1);
        n2 = sortList(n2);
        return merge(n1, n2);
    }
};