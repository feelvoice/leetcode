/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len <= 2) return len;
        
        int ret = 0;
        double k;
        for (int i=0; i<len; i++) {
            map<double, int> m;
            int vertical = 0;
            int same = 0;
            for (int j=0; j<len; j++) {
                if (i == j) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                }
                else if (points[i].x == points[j].x) {
                    vertical++;
                }
                else {
                    k = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
                    ++m[k];
                }
            }
            ret = max(ret, vertical+1+same);
            for (map<double, int>::iterator it=m.begin(); it!=m.end(); ++it) {
                ret = max(ret, it->second + 1+same);
            }
        }
        return ret;
    }
};