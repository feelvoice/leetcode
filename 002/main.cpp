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

    ListNode* add_helper(ListNode* l1, ListNode* l2, int carry) {
        if (carry) {
            if (l1 == NULL && l2 == NULL) {
                return new ListNode(carry);
            }
            else if (l1 == NULL) {
                int digit = l2->val + carry;
                ListNode *list = new ListNode(digit % 10);
                list->next = add_helper(l1, l2->next, digit / 10);
                return list;
            }
            else if (l2 == NULL) {
                int digit = l1->val + carry;
                ListNode *list = new ListNode(digit % 10);
                list->next = add_helper(l1->next, l2, digit / 10);
                return list;
            }
            else {
                int digit = l1->val + l2->val + carry;
                ListNode *list = new ListNode(digit % 10);
                list->next = add_helper(l1->next, l2->next, digit / 10);
                return list;
            }
        }
        else {
            if (l1 == NULL && l2 == NULL) {
                return NULL;
            }
            else if (l1 == NULL) {
                return l2;
            }
            else if (l2 == NULL) {
                return l1;
            }
            else {
                int digit = l1->val + l2->val;
                ListNode *list = new ListNode(digit % 10);
                list->next = add_helper(l1->next, l2->next, digit / 10);
                return list;
            }
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return add_helper(l1, l2, 0);
    }
};