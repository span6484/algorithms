class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int l = 0, r = nums.size()-1;
        while(l < nums.size() && nums[l] == sorted[l]) {
            l++;
        }
        while(r >= l && nums[r] == sorted[r]) {
            r--;
        }
        return r-l+1;
    }
};