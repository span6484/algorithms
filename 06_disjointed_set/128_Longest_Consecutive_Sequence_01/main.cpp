class Solution {
public:
    int Find(int x) {
        while(x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    
    void Union(int x, int y) {
        int x_root = Find(x);
        int y_root = Find(y);
        if(x_root != y_root) {
            // 直接连
            parent[x_root] = y_root;   
        }
    }
    void init(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            parent[nums[i]] = nums[i];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        init(nums);
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != INT_MAX && s.find(nums[i] + 1) != s.end()) {
                Union(nums[i], nums[i] + 1);
            }
            if(nums[i] != INT_MIN && s.find(nums[i] - 1) != s.end()) {
                Union(nums[i], nums[i] - 1);
            }
            s.insert(nums[i]);
        }
        
        int res = 0;
        unordered_map<int, int> count;
        for(auto& pa:parent) {
            int root = Find(pa.first);
            count[root]++;
            res = max(res, count[root]);
        }
        return res;
    }

private:
    unordered_map<int, int> parent;
};