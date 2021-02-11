class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int cur = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[cur-1] != nums[i]) {
                nums[cur++] = nums[i]; 
            }
        }
        return cur;
    }
};