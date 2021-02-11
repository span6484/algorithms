class Solution {
public:
    int findMin(vector<int>& nums) {
        bool flag = true;
        int pre = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(pre > nums[i]) return nums[i];
        }
        return nums[0];
    }
};