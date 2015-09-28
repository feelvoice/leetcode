/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *> &mark) {
        if (node == NULL) return NULL;
        if (mark.find(node) != mark.end()) {
            return mark[node];
        }
        
        mark[node] = new UndirectedGraphNode(node->label);
        for (int i=0; i<node->neighbors.size(); i++) {
            mark[node]->neighbors.push_back(dfs(node->neighbors[i], mark));
        }
        return mark[node];
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode *, UndirectedGraphNode *> mark;
        UndirectedGraphNode *ret = dfs(node, mark);
        return ret;
    }
};