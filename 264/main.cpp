class Solution {
public:
    int nthUglyNumber(int n) {
        queue<int> q[3];
        int factor[3] = {2, 3, 5};
        for (int i=0; i<3; i++) q[i].push(1);
        int ret;
        
        for (int i=0; i<n; i++) {
            ret = min(min(q[0].front(), q[1].front()), q[2].front());
            for (int j=0; j<3; j++) {
                q[j].push(ret * factor[j]);
                if (q[j].front() == ret) q[j].pop();
            }
        }
        return ret;
    }
};