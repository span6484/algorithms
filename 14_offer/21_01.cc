class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i < j) {
            if((nums[i] % 2 == 0) && (nums[j] % 2 != 0)) {
                swap(nums[i], nums[j]);
            } else {
                if(nums[i] % 2 != 0) i++;
                if(nums[j] %2 == 0) j--; 
            }
        }
        return nums;
    }
};