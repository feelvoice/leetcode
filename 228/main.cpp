class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int len = nums.size();
        if (len == 0) return ret;
        
        bool range = false;
        int start;
        char buffer[100];
        for (int i=0; i<len; i++) {
            if (i == 0) {
                start = nums[i];
            }
            else {
                if (nums[i] == nums[i-1] + 1) {
                    range = true;
                }
                else {
                    if (range) {
                        sprintf(buffer, "%d->%d", start, nums[i-1]);
                        ret.push_back(buffer);
                    }
                    else {
                        sprintf(buffer, "%d", start);
                        ret.push_back(buffer);
                    }
                    range = false;
                    start = nums[i];
                }
            }
        }
        if (range) {
            sprintf(buffer, "%d->%d", start, nums[len-1]);
            ret.push_back(buffer);
        }
        else {
            sprintf(buffer, "%d", start);
            ret.push_back(buffer);
        }
        return ret;
    }
};