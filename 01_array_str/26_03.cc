class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int slow = 1, fast = 1;
        while(fast < nums.size()) {
            if(nums[fast] == nums[slow-1]) {
                fast++;
            } else {
                swap(nums[slow++], nums[fast++]);
            }
        }
        return slow;
    }
};