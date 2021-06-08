class UF {
public:
    UF() {}

    int find(int x) {
        if(parent_.find(x) == parent_.end()) {
            parent_[x] = x;
            size_[x] = 1;
            return x;
        }
        while(x != parent_[x]) {
            x = parent_[x];
        }
        return parent_[x];
    }
    bool merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return false;
        if(size_[rootx] > size_[rooty]) {
            parent_[rooty] = rootx;
            size_[rootx] += size_[rooty];
        } else {
            parent_[rootx] = rooty;
            size_[rooty] += size_[rootx];        
        }
        return true;
    }
    int getMaxSize() { 
        for(auto& s : size_) {
            maxSize_ = max(maxSize_, s.second);
        }
        return maxSize_;
    }
private:
    unordered_map<int, int> parent_;
    unordered_map<int, int> size_;
    int maxSize_ = 0;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        UF uf;
        uf.find(nums[0]);
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < INT_MAX && s.find(nums[i] + 1) != s.end()) {
                uf.merge(nums[i], nums[i]+1);
            }
            if(nums[i] > INT_MIN && s.find(nums[i] -1) != s.end()) {
                uf.merge(nums[i], nums[i]-1);
            }
            s.insert(nums[i]);
        }      
        return uf.getMaxSize();
    }
};