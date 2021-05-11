class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r-l)/2;
            if(target == nums[mid]) return mid;
            if(nums[l] < nums[mid]) {   // 前半段有序
                if(nums[l] <= target && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid;
                }
            } else {
                if(nums[mid] < target && target <= nums[r-1]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
        }
        return -1;
    }
};