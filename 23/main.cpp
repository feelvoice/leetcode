struct cmp{
    bool operator() (const ListNode *a, const ListNode *b){
        return a->val < b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        int n = lists.size();
        for (int i=0; i<n; i++) {
            cur = lists[i];
            while (cur) {
                pq.push(cur);
                cur = cur->next;
            }
        }
        while (!pq.empty()) {
            cur = pq.top(); pq.pop();
            cur->next = ret;
            ret = cur;
        }
        return ret;
    }
};