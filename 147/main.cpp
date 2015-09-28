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

    ListNode *insert_sort(ListNode *head, ListNode *remain) {
        if (remain == NULL) {
            return head;
        }
        ListNode *remain_next = remain->next;
        if (head->val >= remain->val) {
            remain->next = head;
            return insert_sort(remain, remain_next);
        }
        else {
            ListNode *cur = head;
            ListNode *prev = NULL;
            while (cur && cur->val < remain->val) {
                prev = cur;
                cur = cur->next;
            }
            remain->next = prev->next;
            prev->next = remain;
            return insert_sort(head, remain_next);
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode *remain = head->next;
        head->next = NULL;
        return insert_sort(head, remain);
    }
};