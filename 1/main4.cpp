struct Node {
    int num;
    int pos;
    Node(int n, int p): num(n), pos(p) {}
    
    bool operator<(const Node &other) {
        return num < other.num;
    }
};

class Solution {
public:
    //Runtime: 16 ms 居然比unordered_map快~ - -
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<Node> vn;
        int size = nums.size();
        for (int i=0; i<size; i++) {
            vn.push_back(Node(nums[i], i));
        }
        sort(vn.begin(), vn.end());
        
        int i=0, j=size-1;
        while (i<j) {
            int sum = vn[i].num + vn[j].num;
            if (sum == target) {
                int index1 = vn[i].pos, index2 = vn[j].pos;
                if (index1 > index2) swap(index1, index2);
                vector<int> ret;
                ret.push_back(index1+1); ret.push_back(index2+1);
                return ret;
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }
        
    }
};