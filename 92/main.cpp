#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *head) {
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        m--; n--;
        
        ListNode *prev = NULL, *tail = NULL, *tmp = NULL;
        ListNode *cur = head;
        for (int i=0; i<m; i++) {
            prev = cur;
            cur = cur->next;
        }
        
        ListNode *rev = NULL;
        for (int i=0; i<=n-m; i++) {
            tmp = cur->next;
            if (i == 0) tail = cur;
            cur->next = rev;
            rev = cur;
            cur = tmp;
        }
        tail->next = cur;
        if (prev == NULL) {  
            return rev;
        }
        else {
            prev->next = rev;
            return head;
        }
    }
};

int main()
{
    Solution s = Solution();
    ListNode *head = new ListNode(3);
    head->next = new ListNode(5);
    
    ListNode *ret = s.reverseBetween(head, 1, 2);
    print_list(ret);
    return 0;
}