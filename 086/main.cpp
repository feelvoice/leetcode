#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        queue<ListNode *> que1, que2; 
        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                que1.push(cur);
            }
            else {
                que2.push(cur);
            }
            cur = cur->next;
        }
        
        ListNode *ret = NULL, *tail = NULL;
        if (que1.empty()) {
            ret = que2.front();
            que2.pop();
        }
        else {
            ret = que1.front();
            que1.pop();
        }
        tail = ret;
        while (!que1.empty()) {
            tail->next = que1.front(); que1.pop();
            tail = tail->next;
        }
        while (!que2.empty()) {
            tail->next = que2.front(); que2.pop();
            tail = tail->next;
        }
        tail->next = NULL;
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    ListNode *head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    ListNode *cur = s.partition(head, 3);
    while (cur) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    
    return 0;
}