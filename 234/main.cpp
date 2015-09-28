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
    bool is_same(ListNode *a, ListNode *b) {
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
    
    ListNode *rev(ListNode *head) {
        ListNode *ret = NULL;
        ListNode *cur = head, *tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = tmp;
        }
        return ret;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *fast = head, *slow = head, *mid;
        do {
            if (fast->next == NULL || fast->next->next == NULL) {
                mid = slow->next;
                slow->next = NULL;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (1);
        mid = rev(mid);
        return is_same(head, mid);
    }
};