class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int maxIdx = 0;
        int i = 0;
        while(i < sz && i <= maxIdx) {
            maxIdx = std::max(maxIdx, i +nums[i]);
            i++;
        }
        return maxIdx >= sz-1 ? true : false; 
    }
};