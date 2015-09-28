/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *dfs(RandomListNode *node, map<RandomListNode *, RandomListNode *> &mark) {
        if (node == NULL) return NULL;
        if (mark.find(node) != mark.end()) {
            return mark[node];
        }
        
        mark[node] = new RandomListNode(node->label);
        mark[node]->next = dfs(node->next, mark);
        mark[node]->random = dfs(node->random, mark);
        return mark[node];
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> mark;
        return dfs(head, mark);
    }
};