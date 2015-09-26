struct cmp{
    bool operator() (const ListNode *a, const ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *cur = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        int n = lists.size();
        for (int i=0; i<n; i++) {
            cur = lists[i];
            if (cur) {
                pq.push(cur);
                cur = cur->next;
            }
        }
        ListNode *ret = NULL;
        ListNode *tail = NULL;
        while (!pq.empty()) {
            cur = pq.top(); pq.pop();
            if (cur->next) {
                pq.push(cur->next);
            }
            if (ret == NULL) {
                ret = cur;
                tail = cur;
            }
            tail->next = cur;
            tail = cur;
        }
        if (tail) tail->next = NULL;
        return ret;
    }
};