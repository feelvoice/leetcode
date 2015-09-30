class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0) return 0;
        int i=0, j=len-1, mid;
        while (i <= j) {
            mid = i + (j-i) / 2;
            if (citations[mid] >= len-mid) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }  
        }
        return len - i;
    }
};